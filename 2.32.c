/*
 * 2.32.c
 *
 *  Created on: Jun 22, 2020
 *      Author: Theo Diehl
 *
 * Calculates the BMI using user input.
 */

#include <stdio.h>

int main(void){

	//creates variables for BMI, weight and height
	float BMI;
	float weight;
	float height;


	//Prompts user for their weight and stores the value in weight
	printf("What is your weight? (in lbs)\n");
	scanf("%f",&weight);

	//prompts user for their height and stores the value in height
	printf("What is your height? (in inches)\n");
	scanf("%f", &height);

	//does the calculation for BMI
	BMI = (weight * 703)/(height*height);

	//prints a table of the meanings to the different BMIs the user can read.
	printf("BMI Values\n"
			"Underweight:  less than 18.5\n"
			"Normal:       between 18.5 and 24.9\n"
			"Overweight:   between 25 and 29.9\n"
			"Obese:        30 or greater\n\n");

	//prints out the user's BMI
	printf("Your BMI is %.2f\n", BMI);

	return 0;

}
