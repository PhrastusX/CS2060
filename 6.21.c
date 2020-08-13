/*
 * 6.21.c Airline Reservation System
 *Created on: Jul 7, 2020
 *Author: Theo Diehl
 *Creates a program to assign seats in a airplane
 */

#include <stdio.h>


#define SIZE 10

void firstClassAssignment(int *ptr, int *ptr2);
void economyAssignment(int *ptr, int *ptr2);

int main(void){

	char errorChoice = 'n';//used if spaces are full to assign new seat
	int choice = 0;//default choice
	int firstClassTicket = SIZE/2;//where first class tickets start in array
	int economyTicket = 0;//where economy tickets start in array


	//creates an array with size 10
	//and initializes all slots to zero
	int seats[SIZE]= {0};

	//creates pointers for a index in array
	int *firstClassptr = &seats[SIZE/2];
	int *economyptr = &seats[0];

	//continues until plane is full
	while(firstClassTicket != SIZE || economyTicket != SIZE/2){

		//default menu
		puts("Please pick a seat\n"
			"1. First Class\n"
			"2. Economy");
		scanf("%d", &choice);//stores user choice


		switch(choice){

		//for first class tickets
		case 1:

			//verifies there is room in first class section
			if((firstClassTicket < SIZE)){
				firstClassAssignment(firstClassptr, &firstClassTicket);

			}//if

			//executes if section is full
			else{

				//asks if the customer would like to chose a different seat
				printf("%s","Sorry there is no more first class tickets\n"
					"Would you like an economy seat instead? \ny/n\n\n");
				scanf(" %c", &errorChoice);

				//assigns seat if user chose y
				if(errorChoice == 'y'){
					economyAssignment(economyptr, &economyTicket);
				}
				//if they choose anything other then 'y'
				else{
					printf("%s", "Next flight leaves in 3 hours\n\n");
				}
			}
			break;

		//for economy tickets
		case 2:

			//tests for empty seats
			if ((economyTicket < SIZE/2)){
				economyAssignment(economyptr, &economyTicket);

		 }//if

			//executes if section if full
			else{
				printf("%s","Sorry there is no more economy tickets\n"
					"Would you like an first class seat instead? \ny/n\n");
				scanf(" %c", &errorChoice);

				//if they will accept a reassignment
				if(errorChoice == 'y'){
					firstClassAssignment(firstClassptr, &firstClassTicket);
				}

				//executes if they did not want reassignment
				else{
					printf("%s", "Next flight leaves in 3 hours\n\n");
				}// inner else
			}//else
			break;
		}//switch
	}//while
	printf("%s", "\nThe plane is now full\n");
}//main

//takes in a pointer to an array and the counter for number of tickets
//assigns seat and prints out ticket
void firstClassAssignment(int *firstClassptr, int *firstClassTicketptr){

	//executes if the seat is not taken and section is not full
	if((*firstClassptr !=1) && *firstClassTicketptr < SIZE ){

		//assigns the seat and marks as full
		*firstClassptr = 1;

		//moves ptr down the array
		(*firstClassptr)++;

		//increments number of tickets
		*firstClassTicketptr = *firstClassTicketptr + 1;


		printf("TICKET\nFirst Class Seat: %d\n\n", *firstClassTicketptr);
	}//if
}//firstClassAssignment()

//takes in a pointer to an array and the counter for number of tickets
//assigns seat and prints out ticket
void economyAssignment(int *economyptr, int *economyTicketptr){
	if((*economyptr !=1) && *economyTicketptr < SIZE/2){

		//assigns the seat and marks as full
		*economyptr = 1;

		//moves ptr down the array
		(*economyptr)++;

		//increments number of tickets
		*economyTicketptr = *economyTicketptr + 1;
		printf("Ticket\nEconomy Seat: %d\n\n", *economyTicketptr);
	}//if
}//economyAssignment()


