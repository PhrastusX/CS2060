/*
 * 4.27.c
 *
 *  Created on: Jun 23, 2020
 *      Author: Theo Diehl
 *
 * Prints out the values that satisfy the pythagorean tripple
 */
#include <stdio.h>

int main(void){

	//initializes variables
	int side1;
	int side2;
	int hypo;

	//three nested for loops that that iterate 500 times
	for(int i = 1; i<500;i++){
		for(int j = i; j<500;j++){
			for(int k = 1; k<500; k++){

				//sets side 1 side 2, and the hypotenuse equal to the variable in their loops
				hypo =k;
				side2 =j;
				side1 = i;

				//checks if the sides satisfy the conditions for pythagorean triples and
				//prints out the lengths of the sides that do.
				if(((side1*side1)+(side2*side2)) == hypo*hypo){

					printf("sides: %d and %d and hypotenuse: %d satisfy the pythagorean triple\n", side1, side2,hypo);
				}
			}
		}
	}


	return 0;
}

