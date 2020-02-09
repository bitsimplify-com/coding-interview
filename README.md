# Setup
run setup.sh script first to setup commit hooks. This helps checking various things before a commit is pushed.

# Instructions

## Structure
- There are .md files which has the questions
- Each Directory has numberd sub-directories e.g., Google/1, Google/2
- Inside each numbered directory there are five files e.g. inside Microsoft/1, there are
- 1.cpp, 1.py, 1.in, 1.out, 1.md
- the .in file has the input that should be passed to the program as input.
- the .out has the expected output. the verifier will run compare the program output with the .out file
- .md file has the question and other documentation. See Google/1/1.md, Google/2/2.md etc for more details

## to verify the programs
run `./utils/verify -r` from the PROJECT_HOME directory. If the output of the program matches the corresponding .out file then the program will succeed otherwise it will print error.

## to run individual program
- Build the program
`g++ Google/1/1.cpp -o 1.exe`
- Run the program by passing the input 1.in and get the output in a separate file 1.prog.out
`./1.exe < Google/1/1.in > 1.prog.out`
- The python program is run directly so we can run the following command
`python3 Google/1/1.py < Google/1/1.in > 1.prog.out`
- Compare the output with the existing .out file.
`diff 1.prog.out Google/1/1.out`
### If the diff does not print anything that means there is no difference. If there is a difference then we need to fix it.

## Machine Learning, Data Science coding and conceptual questions
### Coding questions
- Collect a list of coding questions and write the answer in python, if C++ is possible then do that otherwise only python.
- Follow the structure of company based questions for the input,output,.md,.py file.
- Put as much detail in .md file as possible. e.g., see Microsoft/4/4.md

### Concept questions
- Many websites/blogs have a good collection of such questions (e.g., https://www.analyticsvidhya.com/blog/2016/09/40-interview-questions-asked-at-startups-in-machine-learning-data-science/, https://www.simplilearn.com/machine-learning-interview-questions-and-answers-article)
- Use the above websites for guidance and do your research as well, try to put helpful questions only to reduce noise.
- Each question and answer should be in a separate .md file
- Pay attention to grammar and readability.
