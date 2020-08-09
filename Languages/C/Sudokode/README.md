# Sudokode
Sudokode was a program written in the spring of 2016 for the class *Computer Science I* taught by Professor Arup Guha at the University of Central Florida. The assignment criteria for Sudokode is given in the file *Sudokode.pdf*. I have opted to keep my yellow highlighting on the document, so that the reader may quickly skim through the assignment details.

Sudokode will verify the correctness of a solution for a 9x9 sudoku grid with digits 1 through 9. If the solution is correct, the output will be "YES". If the solution is incorrect, the output will be "NO". Sudokode reads from standard input and writes to standard output. The constraints and formatting of the input is given in the assignment document *Sudokode.pdf*.

## Compiling Sudokode
Sudokode was written in adherance to GCC 5.4.0 which supports C11. To compile Sudokode, write into the terminal:

`gcc -o executable sudokode.c`

*executable* can be replaced by any valid file name. My preference is to substitute *sudokode* for *executable* like this:

`gcc -o sudokode sudokode.c`

## Running Sudokode
Assuming *sudokode* is the substitute for *executable*, here is an example of how to run Sudokode using the input file *sudokode.txt* and the output file *sudokode.out*:

`sudokode < sudokode.txt > sudokode.out`

Alternatively, you may wish to print the output to the console rather than to a file:

`sudokode < sudokode.txt`

There are many other permutations, but the general idea is to use standard input and standard output.

## Repository Files
1. *sudokode.c* is the source code.

2. *sudokode.pdf* is the assignment document given by the professor.

3. *sudokode.in* is the test case used by the professor to grade the students' program submissions. Click [here](http://www.cs.ucf.edu/courses/cop3502/fall2015/programs/P1/sudokode.in) for the link to the professor's original input file, and click [here](http://www.cs.ucf.edu/courses/cop3502/fall2015/programs/P1/sudokode.out) to see the professor's intended output.

4. *sudokode.txt* is the sample input given from *Sudokode.pdf*.

And of course, you are reading the file *README.md*! :smile:

## Authors
* Kevin Tran - FridaySky

## License
This project is not licensed, but please do not share my code to prevent other students from copying my code!

## Acknowledgments
* Professor Guha provided his students with the insight to use integer frequency arrays. I have taken his advice, and I have gone a step further by implementing boolean arrays instead.
