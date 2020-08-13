/*CS 2060
Author: Theo Diehl
Created on: Jul 18, 2020
Assingment: ReverseStrings.c*/

#include <stdio.h>


void recursiveToken( char *stringtok);


int main(void){

	char string[1024];

	printf("%s", "Input a string to be printed in reverse\n");

	scanf("%1023[^\n]s", string);

	char *stringtok = strtok(string, " ");

	char *firstword = stringtok;

	recursiveToken(stringtok);

	puts(firstword);
}//main

void recursiveToken(char *stringtok){


		while(stringtok != NULL){

			stringtok = strtok(NULL, " ");

			recursiveToken(stringtok);

			if(stringtok != NULL){
				printf("%s ",stringtok);
			}//if

		}//while

}//recursiveToken







