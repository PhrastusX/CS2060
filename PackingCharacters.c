/*
 ============================================================================
 Name        : PackingCharacters.c
 Author      : Theo Diehl
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void displayBits(unsigned int value);
unsigned packCharacters(char char1, char char2, char char3, char char4);

int main(void) {


	char char1;
	char char2;
	char char3;
	char char4;


	puts("Please enter 4 characters");

	scanf("%c %c %c %c", &char1, &char2, &char3, &char4);



	displayBits(packCharacters(char1, char2, char3, char4));

	return EXIT_SUCCESS;
}

//packs all characters into a 4 bytes
unsigned packCharacters(char char1, char char2, char char3, char char4){

	puts("first character before");
	displayBits(char1);
	puts("\n");

	//this code shifts the first character 8 bits
	unsigned packChar = char1;
	packChar <<= 8;

	//packs char2 onto the shifter char1
	unsigned packed2 = packChar | char2;

	puts("After packing char1 and char2");
	displayBits(packed2);
	puts("\n");

	//shifts the new unsigned int 8 more spaces
	unsigned packChar2 = packed2;
	packChar2 <<=8;

	//packs char3 onto the previously constucted int
	unsigned packed3 = packChar2 | char3;
	puts("After packing char 3");
	displayBits(packed3);
	puts("\n");

	//shifts 8 more bits
	unsigned packChar3 = packed3;
	packChar3 <<=8;

	unsigned packed4 = packChar3 | char4;
	puts("After packing char 4");
	displayBits(packed4);
	puts("\n");



	puts("Final Result");
	return packed4;


}

//taken from text book pg 418
void displayBits(unsigned int value){
	unsigned  displayMask = 1 << 31;

	for(int i = 1; i <=32; ++i){
		putchar(value & displayMask ? '1' : '0');
		value <<= 1;

		if(i %8 == 0){
			putchar( (' '));
		}
	}

}
