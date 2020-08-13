/*
 * Hello.c
 *
 *  Created on: Jun 22, 2020
 *      Author: Theo Diehl
 * Creates some shapes using printf()
 */

#include <stdio.h>

//creates the designs that print to the console.

int main(void){
	int c;

	if((c = getchar()) != EOF){
		printf("%c\n", c);
		main();



	}

	return 0;
}

