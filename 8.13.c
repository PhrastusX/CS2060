/*CS 2060
Author: Theo Diehl
Created on: Jul 12, 2020
Assingment: 8.13.c
Program Reads from a file and converts
Words to pig latin*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//prototype
void moveUp(char *array, int length);
void toPigLatin(char *strptr);

int main(void){

	FILE *myFile;//pointer to file

	char String[1024] = " ";//empty string array to hold characters in file
	char ay[] = "ay";//used to add ay onto string
	char character;//used for filling up string array

	int count = 0;

	//points to the file
	if ((myFile = fopen("/Users/theo/eclipse-workspace/8.13/englishWords.txt", "r")) == NULL){
			puts("File cannot be found\n");
	}

	//loop ends when end of file is reached
	while(!feof(myFile)){

		fgets(String, 1023, myFile);

		//creates a pointer to new string
		char *strptr = strtok(String, " ");

			//executes as long as strptr points to word in String
			while (strptr != NULL){

				//converts to pig latin and prints out translated string
				toPigLatin(strptr);
				printf("%s%s " ,strptr, ay);
				strptr = strtok(NULL, " ");

			}
	}
	//closes file
	fclose(myFile);

}//main

//moves all characters up in the string
void moveUp(char *array, int length){

	//loops through and overwrites first element moves all
	//characters up one slot
	for(int i = 0; i < length-1; i++){

		array[i] = array[i+1];

	}//for
}//moveUp()

//converst a string to pig latin
void toPigLatin(char *strptr){

	//finds length of the string
	int length = strlen(strptr);

	//stores first character before it is overwritten
	char first = strptr[0];
	moveUp(strptr, length);

	//puts the first character at the end of string
	strptr[length-1] = tolower(first);

}//toPigLatin()
