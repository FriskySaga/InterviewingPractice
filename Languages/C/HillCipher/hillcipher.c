/***
	Kevin Tran
	CIS3360.0001 - Spring 2017
	Programming Assignment #1: Hill Cipher

	Comment: I wasted about 2 hrs before I realized *letterCount++ was different from *letterCount += 1.
***/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PLAINTEXT_SIZE 10000

int **save_key(FILE *fpKey, int numRows, int numCols);
int get_plaintext(FILE *fpPlain, char *letters, int matrixDimensions);
void eighty_char(int count);
char *Hill_cipher(int matrixSize, int **keyMatrix, int numLetters, char *plaintext);
void encrypt_block(char* encryptedBlock, int matrixSize, int **keyMatrix, char *blocks, int *letterCount);
int get_letter(int dotProduct);
void free_key(int **grid, int numRows);

/*
	Given an arbitrary number of command line arguments, echo argv[1] and argv[2].
	argv[1] is the file name of the input key matrix file, and argv[2] is the file name of the input plaintext file.
*/
int main(int argc, char **argv)
{
	//Open the input key matrix file.
	FILE *fpKey = fopen(argv[1], "r");

	//Record the size of the matrix.
	int matrixSize;
	fscanf(fpKey, "%d", &matrixSize);

	//Output the header to the console, and save the key matrix to a dynamically allocated array.
	printf("\n\nKey Matrix:\n\n");
	int **keyMatrix = save_key(fpKey, matrixSize, matrixSize);

	//Close the input key matrix file.
	fclose(fpKey);

	//Open the input plaintext file.
	FILE *fpPlain = fopen(argv[2], "r");

	//Output the header to the console, and record the plaintext to the array. Resize the array appropriately.
	printf("\n\nPlaintext:\n\n");
	char *plaintext = (char *) malloc(PLAINTEXT_SIZE * sizeof(char));
	int numLetters = get_plaintext(fpPlain, plaintext, matrixSize);
	plaintext = (char *) realloc(plaintext, (numLetters+1) * sizeof(char));

	//Close the input plaintext file.
	fclose(fpPlain);

	//Output the header to the console. Create the ciphertext using the key and plaintext. This implementation opts
	//to save the ciphertext to memory in case we need the data for something else later.
	printf("\n\n\nCiphertext:\n\n");
	char *ciphertext = Hill_cipher(matrixSize, keyMatrix, numLetters, plaintext);
	printf("\n");

	//Free the key matrix array, free the plaintext array, and free the ciphertext array.
	free_key(keyMatrix, matrixSize);
	free(plaintext);
	free(ciphertext);

	return 0;
}

/*
	Return a pointer to a dynamically allocated 2D integer array of size numRows x numCols with input key matrix data.
*/
int **save_key(FILE *fpKey, int numRows, int numCols)
{
	//Dynamically allocate memory for a 2D array, and fill it with data as we go along. Echo the data.
	int **grid = (int **) malloc(numRows * sizeof(int *));
	for (int i = 0; i < numRows; i++)
	{
		grid[i] = (int *) malloc(numCols * sizeof(int));

		for (int j = 0; j < numCols; j++)
		{
			fscanf(fpKey, "%d", &grid[i][j]);
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}

	return grid;
}

/*
	Process the plaintext file and save only the letters; ignore all other characters. Pad the processed plaintext
	if neessary. Echo the processed plaintext. Return an integer indicating the number of letters in the plaintext.
*/
int get_plaintext(FILE *fpPlain, char *letters, int matrixDimensions)
{
	int numLetters = 0;
	char input[PLAINTEXT_SIZE];

	//Read in the plaintext to the 'input' array, and filter only the letters into the 'letters' array.
	for (int i = 0; i < PLAINTEXT_SIZE; i++)
	{
		fscanf(fpPlain, "%c", &input[i]);

		//Check that we are not processing the null character. Echo the plaintext letters as we go along.
		if (input[i] != '\0')
		{
			//Using ASCII values, if the character is a lower-cased letter, then store it into the 'letters' array.
			if (input[i] >= 'a' && input[i] <= 'z')
			{
				letters[numLetters] = input[i];
				printf("%c", letters[numLetters]);

				//Move onto the next index and check if 80 characters have been printed already.
				numLetters++;
				eighty_char(numLetters);
			}

			//Using ASCII values, if the character is an upper-cased letter, then store its lower-cased equivalent by adding 32.
			else if (input[i] >= 'A' && input[i] <= 'Z')
			{
				letters[numLetters] = input[i] + 32;
				printf("%c", letters[numLetters]);

				//Move onto the next index and check if 80 characters have been printed already.
				numLetters++;
				eighty_char(numLetters);
			}
		}

		//If we run into a null character, then there are no more characters in the input file.
		else break;
	}

	//Check to see if padding is necessary. If so, pad with the letter 'x' and print the padding.
	while (numLetters % matrixDimensions != 0)
    {
        strcat(letters, "x");
        printf("%c", letters[numLetters]);
        numLetters++;
    }

    return numLetters;
}

/*
    The purpose of this function is to correctly format the output by only allowing 80 characters on each
    line before printing a new line. The function receives as input the position number of the current character,
    i.e., the nth character in a string with n starting at 1.
*/
void eighty_char(int count)
{
    if (count % 80 == 0)
        printf("\n");
}

/*
    Given the dimensions of the key matrix, the key matrix itself, the number of letters in the plaintext,
    and an array storing all of the letters of the plaintext, encrypt the plaintext with the key using the
    Hill cipher. Return the resulting ciphertext array of characters.
*/
char *Hill_cipher(int matrixSize, int **keyMatrix, int numLetters, char *plaintext)
{
    //Dynamically allocate memory for an empty character array to store the ciphertext.
    char *ciphertext = (char *) calloc((numLetters+1), sizeof(char));

    //Dynamically allocate memory for a character array to store the blocks of length matrixSize.
    char *blocks = (char *) malloc((matrixSize+1) * sizeof(char));

    //Dynamically allocate memory for a character array to store the encrypted block.
    char *encryptedBlock = (char *) malloc((numLetters+1) * sizeof(char));

    //Partition the plaintext into blocks of matrixSize.
    int cipherIndex = 0;
    int letterCount = 0;
    for (int i = 0; i < numLetters; i+= matrixSize)
    {
        //Transfer the indices of each block into the array 'blocks'.
        for (int j = i, k = 0; j < (i + matrixSize); j++, k++)
            blocks[k] = plaintext[j];

        //Encrypt each block.
        encrypt_block(encryptedBlock, matrixSize, keyMatrix, blocks, &letterCount);

        //Store the encrypted block into the 'ciphertext' array.
    	int j = 0;
        while (cipherIndex < i + matrixSize)
        {
        	ciphertext[cipherIndex] = encryptedBlock[j];
        	cipherIndex++, j++;
        }
    }

    //Tidy up.
    free(blocks);
    free(encryptedBlock);

    return ciphertext;
}

/*
    Given a pointer to an array with the encrypted block, the size of the key matrix, the key matrix itself, and
    an array containing the partitioned blocks of the plaintext, use matrix multiplication on the key matrix and
    the partitioned blocks to encrypt the blocks of plaintext into the encrypted block array that is passed by
    reference. Print the encrypted letters as we go along.
*/
void encrypt_block(char* encryptedBlock, int matrixSize, int **keyMatrix, char *blocks, int *letterCount)
{
    //Dynamically allocate memory for an integer array to store the numeric equivalences of each letter
    //from 'blocks', starting with a = 0 and ending at z = 25.
    int *numericBlock = (int *) malloc((matrixSize+1) * sizeof(int));

    //Convert each letter from 'blocks' to its numeric equivalent.
    for (int i = 0; i < matrixSize; i++)
        numericBlock[i] = blocks[i] - 'a';

    //Perform matrix multiplication on keyMatrix and numericBlock.
    for (int i = 0; i < matrixSize; i++)
    {
        //Compute the dot product of the ith row in the key and the block.
        int dotProduct = 0;
        for (int j = 0; j < matrixSize; j++)
            dotProduct += keyMatrix[i][j] * numericBlock[j];

        //Convert the dot product value to its corresponding alphabet letter. Print as we go along.
        encryptedBlock[i] = get_letter(dotProduct);
        printf("%c", encryptedBlock[i]);
        *letterCount = *letterCount + 1;
        eighty_char(*letterCount);
    }

    //Tidy up.
    free(numericBlock);
}

/*
    Given an integer, do the arithmetic modulo 26, and convert the resultant integer to a letter from the
    alphabet, starting with a = 0. Return the ASCII value associated with the relevant alphabet character.
*/
int get_letter(int dotProduct)
{
    return dotProduct % 26 + 'a';
}


/*
	Free the memory of the 2D array containing the key matrix.
*/
void free_key(int **grid, int numRows)
{
	for (int i = 0; i < numRows; i++)
		free(grid[i]);
	free(grid);
}
