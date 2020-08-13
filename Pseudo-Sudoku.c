/*CS 2060
Author: Theo Diehl
Created on: Jul 23, 2020
Assingment: Pseudo-Sudoku.c
Checks the validity of a 9x9 sudoku board.  Prints valid or invalid*/


#include <stdio.h>
#include <stdlib.h>

//constants for rows and columns
#define ROW 9
#define COLUMN 9


struct board {
	char puzzle[ROW][COLUMN];//the puzzle board
};

//Prototypes
void test_puzzle(char line[], int start);
int test_Rows(char array [ROW][COLUMN]);
int test_Columns(char array [ROW][COLUMN]);

int main(void) {

	FILE *myFile;
	int i = 0;//counter in while loop

	char character;//character being read from file
	char line[2048];//storage for what is in the file

	//opens file
	if ((myFile = fopen("/Users/theo/eclipse-workspace/Pseudo-Sudoku/puzzle.txt", "r")) == NULL){
		puts("File cannot be found\n");
	}

	//while the file end of file is not true this while loop will continue
	while(!feof(myFile)){

		//scans the file and sets character = to the character in the file

		fscanf(myFile, "%c", &character);

				//special condition at the end of file. prevents last character printed
				//twice
				if(!feof(myFile)){

					//insert the character into line array
					line[i] = character;
					i++;
				}//if


		}//while

	//the first number in the file is used as the condition for switch statement
	int countNumPuz = line[0] - '0';

	//how many puzzles will be read
	switch(countNumPuz){


	//for each case the function test_puzzle will read from the line array
	//and start when the next puzzle takes place every 90 characters
	case 1:
		test_puzzle(line,2);
		break;

	case 2:
		test_puzzle(line,2);
		test_puzzle(line, 92);
		break;

	case 3:
		test_puzzle(line,2);
		test_puzzle(line, 92);
		test_puzzle(line,182);
		break;

	default:
		printf("%s", "Please input a value between 1 and 3, and try again");
	}//switch

	return EXIT_SUCCESS;
}//main


//function first puts an array into a 2D array,
//calls test_Rows and Test Column to test validity,
//then prints valid or invalid
void test_puzzle(char line[], int start){

	//board == puzzle
	struct board puzzle;


	unsigned int i=0,j=0,k=start;//i = rows j = columns k is for line array

	//executes while less than 9
	while (i < ROW){

		//fills columns
		for(j = 0; j < COLUMN; j++){

			//skips new line characters in array
			if (line[k] == '\n'){
				k++;

			}//if

			//puts the character from array into array
			puzzle.puzzle[i][j]= line[k++];

			}//for

			i++;

	}//while

	//tests the rows and columns
	int testrow = test_Rows(puzzle.puzzle);
	int testcolumn = test_Columns(puzzle.puzzle);

	//if both are true prints out valid
	if(testrow == 1 && testcolumn == 1){
		printf("%s\n", "VALID");
	}
	//else the puzzle is invalid
	else{
		printf("%s\n", "INVALID");
	}
}//put_in_2D_Arrary


//tests the rows for any duplicate values
int test_Rows(char array [ROW][COLUMN]){


	int i,j,k;//i = row, j = column k = row

	//test for each row
	for ( i = 0; i < ROW; i++){
		//each column
		for(j = 0; j < COLUMN; j++){
			//tests the start value(i,j) vs every other number
			for(k = 1; k <ROW; k++){
				if ((array[j][i] != array[j][k])){

				}
				//case when it is comparing the same location
				else if (i == k){

				}
				//if it reaches here there is a duplicate in row
				else{
					return 0;
				}
			}

		}
	}
	//if it makes it through the
	return 1;
}//test_Rows

//test each column for validity
int test_Columns(char array [ROW][COLUMN]){
	int i,j,k;//i = column j = row; k = column

	//test for each column
	for ( i = 0; i < COLUMN; i++){
		//for each row
		for(j = 0; j < ROW; j++){
			//each item in that column
			for(k = 1; k <COLUMN; k++){
				if ((array[i][j] != array[k][j])){

				}
				//when comparing to itself skip
				else if (i == k){

				}
				//reaches here the puzzle is invalid
				else{
					return 0;
				}
			}

		}
	}
	//if true
	return 1;
}//test_Columns
