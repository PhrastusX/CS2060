/*CS 2060
Author: Theo Diehl
Created on: Jul 11, 2020
Assingment: Question3.c
Tests for light switches on at the end of the day.
very confusing why it uses a program to do this.
*/

#include <stdio.h>

#define SIZE  7

void numRooms(int array[]);
void printRooms(int array[]);

int main(void){


	unsigned start,j, i ;//tracks room numbers and how many movements are done

	int lights[SIZE] = { };//initializes int array



	//outer for controls which room the person comes out of
	for (i = 0; i <= SIZE - 1; i++){
		start = i+1;

		//inner for controls movement down the hall
		for (j = i; j <= SIZE-1; j = start + j){


			//if light is off(0) turns it on(1)
			if(lights[j] == 0){
				lights[j] = 1;
			}
			//if light if on(1) turns it off
			else{
				lights[j] = 0;

			}//else



		}//while

	}//for


	numRooms(lights);//prints number of lights on
	printRooms(lights);//prints the room numbers with lights on

}//main

//counts number of rooms with lights on
void numRooms(int array[]){
	unsigned j;
	int count= 0;//keeps track of rooms with lights on

		//iterates through the array checking for lights on(1) and
	    //incrementing count
		for(j = 0; j < SIZE; j++){
				if(array[j]==1){
					count++;
				}//if
			}//for
		printf("There were %d rooms with The lights on"
				" in %d rooms.\n\n", count, SIZE);

}//numRooms()

//prints the rooms with lights on
void printRooms(int array[]){
	unsigned i = 0;

	//iterates through the array and prints the rooms with lights on(1)
	for( i; i < SIZE; i++){
		if(array[i] == 1){
			printf("Room %u, has its light on.\n", (i+1));
		}//if
	}//for


}//printRooms()
