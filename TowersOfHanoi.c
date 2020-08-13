/*
 * TowersOfHanoi.c
 *
 *  Created on: Jun 25, 2020
 *      Author: theo
 */

#include <stdio.h>
#include <stdlib.h>

int towers_of_hanoi(unsigned n, unsigned p1, unsigned p2, unsigned p3);

int main(void){

	towers_of_hanoi(2, 1 , 2 , 3);

	return 0;
}

/*p1(or the value in the first spot) represents the initial peg with the smallest value in it
*p2(the value in the second slot) represents the holder peg
*p3(the value in the third slot) represents where to move the next biggest plate
*This function moves the initial values input to the respective pegs*/

int towers_of_hanoi(unsigned n, unsigned p1, unsigned p2, unsigned p3){

	//this is the base case
	if(n == 1){
		printf("%d ---> %d\n", p1 , p3);
	}
	else{
		//this is the recursion decrement n so eventually program will reach the base case
		towers_of_hanoi(n-1, p1,p3,p2);
		printf("%d ---> %d\n", p1 , p3);
		towers_of_hanoi(n-1, p2,p1,p3);
	}
	return 0;
}
