/*
 * 2.27.c
 *
 *  Created on: Jun 22, 2020
 *      Author: Theo Diehl
 *
 *  Prints a checkerboard pattern using multiple printf() statements
 *  and using one.
 */
#include <stdio.h>

int main(void){

	//using 8 printf statements to make a checker board pattern

	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n");
	printf("* * * * * * * *\n");
	printf(" * * * * * * * *\n\n");

	//using the least amount of printf statements
	printf("* * * * * * * *\n"
		" * * * * * * * *\n"
		"* * * * * * * * \n"
		" * * * * * * * *\n"
		"* * * * * * * * \n"
		" * * * * * * * * \n"
		"* * * * * * * * \n"
		" * * * * * * * * \n");
	return 0;
}

