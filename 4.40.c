/*
 * 4.40.c
 *
 *  Created on: Jun 23, 2020
 *      Author: Theo Diehl
 *
 *  Calculates population growth by year.
 */
#include <stdio.h>

int main(void){

	//set the world population and an initial world pop(to be used for when it doubles)
	//growthrate of 1%
	float worldPop = 7800000000;
	float initialWorldPop = 7800000000;
	float growthRate = .01;

	//loops 75 years into the future
	printf("Year\t\tPopulation\t\tGrowth Rate\n");
	for(int i = 0; i<=75;i++){

		//increases world population by the previous years and the current years growth rate
		worldPop = worldPop + (worldPop * growthRate);

		//prints a table first the year, then the population and then the growth rate
		printf("%d\t\t%.2f\t\t%.2f\n", 2020+i,worldPop, growthRate);


		//if the world population is greater than the start years population prints a statement
		if(worldPop > initialWorldPop*2){
			printf("The worlds population doubled in %d\n", 2020+i);

			//sets the initial population = to the current year's
			initialWorldPop = worldPop;
		}
	}
	return 0;
}

