#!/usr/bin/env python3
"""
To run and test the program for each company
./utils/verify -r

Verifier for list of files. To test run from the PROJECT_HOME directory.
./utils/verify -f
If the file list verifier does not work then you may want to use the utils/fixFileNames.sh
script or try to edit that script for your needs and makes sure required files are there.
Each directory should have x.in, x.out, x.cpp, x.py

To verify a company, run like this
./utils/verify.py -c Google

Done:
- Verify that each question has cpp,py,in,out,md files
- Generate warning in the following cases:
    - If there are extra files
    - If any file is empty then
- Run c++ programs and verify if output matches the expected output.

TODO:
- Run python program and verify if output matches the expected output.
- Option to verify one company or all.
"""

from argparse import ArgumentParser
import os
import re
import shutil
import subprocess
import sys

def is_c_file(f):
    return f.endswith('.c') or f.endswith('.cpp')

def is_py_file(f):
    return f.endswith('.py')

def is_in_file(f):
    return f.endswith('.in')

def is_out_file(f):
    return f.endswith('.out')

def is_md_file(f):
    return f.endswith('.md')

def error_reporter(err, level):
    if level=="Error":
        print("Error:", err)
    elif level=="Print":
        print(err)
    else:
        print(level, err)
    pass

def get_company_list():
    # TODO: Get list using os.list_dir
    return ['Microsoft', 'Uber']

def check_include_formatting(filename):
    reg = re.compile(r'#include.*".*"')
    with open(filename) as f:
        for line in f:
            mo = re.search(reg, line)
            if mo:
                error_reporter("Non standard includes not allowed, use only standard headers with angle brackets: " +
                        f.name, "Error")
                return False
    return True

def verify_required_files(d):
    c_file_found = False
    py_file_found = False
    in_file_found = False
    out_file_found = False
    ret = True
    for f in os.listdir(d):
        if is_c_file(f):
            c_file_found = True
            ret = ret and check_include_formatting(os.path.join(d, f))
        elif is_py_file(f):
            py_file_found = True
        elif is_in_file(f):
            in_file_found = True
        elif is_out_file(f):
            out_file_found = True
        elif is_md_file(f):
            out_file_found = True
        else:
            error_reporter("Unknown File: " + os.path.join(d, f), "Error")
    if not c_file_found or not py_file_found or not in_file_found or not out_file_found:
        error_reporter("Required file not found in " + d, "Error")
        ret = False
    return ret

def verify_file_list_c(c):
    ret = True
    for subdir in os.listdir(c):
        if not verify_required_files(os.path.join(c, subdir)):
            ret = False
    return ret

def verify_file_list(d):
    ret = True
    if d == "all":
        company_list = get_company_list()
        for c in company_list:
            if verify_file_list_c(c):
                error_reporter("All files found for " + c, "PASS")
            else:
                error_reporter("All files not found for " + c, "FAIL")
    return ret

def read_file_contents(d):
    base = os.path.basename(d)
    f = os.path.join(d, base+'.out')
    with open(f) as fo:
        r = fo.readlines()
        return ''.join(r)

def get_expected_output(d):
    o = read_file_contents(d)
    #print('expected out:', o.strip() + '|')
    return o.strip()

# Returns the output
def run_c_program(c_file, scratch):
    print("Executing Program:", c_file)
    base = os.path.basename(c_file)
    base_without_ext = base[:-4] # Remove .cpp
    output_file=os.path.join(scratch, base+".out")
    input_file=os.path.join(os.path.dirname(c_file), base_without_ext+".in")
    input_file_bytes = b''
    try:
        with open(input_file, "rb") as input_file_data:
            input_file_bytes = input_file_data.read()
    except IOError:
        error_reporter("No input file " + input_file + " in: " + os.path.dirname(c_file), "Error")
        return ""
    subprocess.call(["g++", c_file, "-o", output_file])
    # timeout after 5 seconds
    timeout=5
    output = ''
    try:
        tmp=subprocess.check_output(output_file, input=input_file_bytes, timeout=timeout)
        output = tmp.decode("utf-8")
    except subprocess.TimeoutExpired:
        print("Timed out after {} seconds".format(timeout))

    return output

# Returns the output
def run_py_program(c_file, scratch):
    print("Executing Program:", c_file)
    base = os.path.basename(c_file)
    base_without_ext = base[:-3] # Remove .py
    input_file=os.path.join(os.path.dirname(c_file), base_without_ext+".in")
    input_file_bytes = b''
    try:
        with open(input_file, "rb") as input_file_data:
            input_file_bytes = input_file_data.read()
    except IOError:
        error_reporter("No input file " + input_file + " in: " + os.path.dirname(c_file), "Error")
        return ""
    tmp=subprocess.check_output(["python3", c_file], input=input_file_bytes)
    return tmp.decode("utf-8")

def run_program(program_dir, scratch):
    files = os.listdir(program_dir)
    test_pass = 0
    test_fail = 0
    for f in files:
        ip = os.path.join(program_dir, f)
        output = None
        if is_c_file(f):
            output = run_c_program(ip, scratch)
        if is_py_file(f):
            output = run_py_program(ip, scratch)
        if output:
            ex=get_expected_output(program_dir)
            output = output.strip()
            if output != ex:
                error_reporter("Mismatch output in " + program_dir, "Error")
                print("Expected:" + ex + ", with len:", len(ex), ", Got:" + output, ", with len:", len(output))
                test_fail += 1
            else:
                error_reporter("Output matched in " + program_dir, "Print")
                test_pass += 1
    return test_pass, test_fail


def run_programs(company_dir, scratch):
    dirs = os.listdir(company_dir)
    test_pass = 0
    test_fail = 0
    for subdir in dirs:
        dirname = os.path.join(company_dir, subdir)
        if os.path.isdir(dirname):
            p,f = run_program(dirname, scratch)
            test_pass += p
            test_fail += f
    return test_pass, test_fail

def run_all_companies(scratch):
    company_list = get_company_list()
    for c in company_list:
        verify_company(c, scratch)

def verify_company(company_name, scratch):
    print("Verifying: ", company_name)
    verify_file_list(company_name)
    p,f = run_programs(company_name, scratch)
    return p,f

def verify_all(scratch):
    company_list = get_company_list()
    test_pass = 0
    test_fail = 0
    for c in company_list:
        p,f = verify_company(c, scratch)
    return test_pass, test_fail

def main():
    parser = ArgumentParser()
    parser.add_argument("-a", "--all",
                        action='store_true',
                        help="Verify everything")
    parser.add_argument("-c", "--company",
                        default="",
                        choices=get_company_list(),
                        help="Verify a specific company",)
    parser.add_argument("-f", "--file_list",
                        action='store_true',
                        help="Verify if all the files are present, with -c it will only verify for that company",)
    parser.add_argument("-r", "--run",
                        action='store_true',
                        help="Verify if all the files are present, with -c it will only verify for that company",)
    parser.add_argument("-o", "--output",
                        default="scratch",
                        help="Print the reports in the file specified as parameter",)
    parser.add_argument("-s", "--scratch",
                        default="scratch",
                        help="scratch directory to keep temporary files, this will be cleaned up on program completion")
    parser.add_argument("-k", "--keep",
                        default=False,
                        help="Keep the temporary files",)

    ret=False
    try:
        args = parser.parse_args()
    except:
        parser.error("Invalid Options.")
        sys.exit(ret)


    # The $PROJECT_HOME/scratch directory
    scratch="scratch"
    if args.all:
        verify_all(scratch)
    if args.company != "":
        p,f = verify_company(args.company, scratch)
        error_reporter(p, "PASS:")
        error_reporter(f, "FAIL:")
    if args.file_list:
        ret=verify_file_list("all")
    if args.run:
        run_all_companies(scratch)

    if not args.keep:
        # Cleanup the scratch directory
        for root, dirs, files in os.walk(scratch):
            for f in files:
                os.unlink(os.path.join(root, f))
            for d in dirs:
                shutil.rmtree(os.path.join(root, d))
    if ret == True:
        sys.exit(0)
    else:
        sys.exit(1)


if __name__ == "__main__":
    main()
