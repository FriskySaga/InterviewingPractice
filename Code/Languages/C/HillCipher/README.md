# Hill Cipher
This was a program written in the spring of 2017 for the class *Security in Computing* taught by Professor Michael McAlpin at the University of Central Florida. The assignment criteria is given in the file *CIS3360-17Spring-Prog-1-HillCipher.pdf*.

This is a program that encrypts the alphabetic letters in a file using the Hill cipher where the Hill matrix can be any size from 2 x 2 up to 9 x 9.

## Compiling on Ubuntu
This program was written in adherance to GCC 7.3.0 which supports C11. To compile, write into the terminal:

`gcc -o executable hillcipher.c`

*executable* can be replaced by any valid file name. My preference is to substitute *hillcipher* for *executable* like this:

`gcc -o hillcipher hillcipher.c`

## Running on Ubuntu
Assuming *hillcipher* is the substitute for *executable*, here is an example of how to run the program using the input files *inkey1.txt* and *infile1.txt*:

`./hillcipher inkey1.txt infile1.txt`

Without loss of generality, you can do the same for all other inkey and input files. Please see the file *p1TestOutput.pdf* for reference.

## Authors
* Kevin Tran - FridaySky

## License
This project is not licensed, but please do not share this code since my professor may reuse this assignment in a future semester.
