/*CS 2060
Author: Theo Diehl
Created on: Jul 20, 2020
Assingment: TelephoneNumbers.c
This program inputs a telephone number and outputs a number in string form
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){

	char teleNumber[20];
	char sevenDigits[8];
	char *remainderptr;
	puts("Please input a Telephone Number");

	scanf("%19[^\n]s", teleNumber);

	const char *areaCode = strtok(teleNumber, " ()-");
	char *firstThree = strtok(NULL, " -");
	char *lastFour = strtok(NULL, "");

	int intAreaCode = atoi(areaCode);

	strcat(sevenDigits, firstThree);
	strcat(sevenDigits, lastFour);

	long longPhone = strtol(sevenDigits, &remainderptr, 0);


	printf("Area Code: %d\nPhone Number: %ld", intAreaCode, longPhone);
}
