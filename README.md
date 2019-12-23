# Setup
run setup.sh script first to setup commit hooks. This helps checking various things before a commit is pushed.

# Instructions

## Structure
There are .md files which has the questions
Each Directory has numberd sub-directories e.g., Microsoft/1, Microsoft/2
Inside each numbered directory there are five files e.g. inside Microsoft/1, there are
1.cpp, 1.py, 1.in, 1.out, 1.md
the .in file has the input that should be passed to the program as input.
the .out has the expected output. the verifier will run compare the program output with the .out file
.md file has the question and other documentation.

## to verify the programs
run `./utils/verify -f` from the PROJECT_HOME directory.
