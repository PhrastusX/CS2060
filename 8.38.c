/*CS 2060
Author: Theo Diehl
Created on: Jul 14, 2020
Assingment: 8.38.c
Program checks input words for spam words*/

#include <stdio.h>


int main(void){

	//chose 10 words that are common in spam emails
	char *spamWords[] = {"additional", "income", "own", "boss",
			"best", "price", "cash", "bonus", "dollar", "consolidate",
			"money"};

	char inputWords[1024];//initialize input words array
	int spamCounter = 0;//counter keeps track of words


	//asks user for the email they would like to check and stores in inputWords
	printf("%s", "Type in words to be checked by the spam checker\n");
	scanf("%1023[^\n]", inputWords);


	//creates first token
	char *inputPtr = strtok(inputWords, " ");

		//executes as long as the ptr has a word
		while(inputPtr != NULL){

			//iterates through spam words
			for(unsigned i = 0; i < 11; i++){

				//compares the word in input to spam words
				int j = strcmp(spamWords[i], inputPtr);

				//if there is a match increments spam counter
				if (j == 0){
					spamCounter++;
				}

			}
			//gets next word in input words
			inputPtr = strtok(NULL, " ");
		}//while

	//prints final value for spam counter
	printf("The string has a spam value of: %d", spamCounter);

}
