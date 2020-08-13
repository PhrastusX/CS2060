/*
 * 4.28.c
 *
 *  Created on: Jun 23, 2020
 *      Author: Theo Diehl
 *
 *  Creates a program for calculating pay based on different conditions
 */

#include <stdio.h>

int main(void){

	//sets variables for the control statement and switch statement
	int paycode;
	int control = 0;

	//sets variables for salary employees
	float salary=0;
	float weeklyPay=0;

	//sets variables for hourly employees
	float hours =0;
	float payrate =0;
	float overtime = 0;

	//sets variables for commission employees
	float sales = 0;
	float commission = 0;

	//sets variables for pieceworkers
	int items = 0;
	float payPer = 1.25;



	//control enter 1 to exit program
	while(control != -1){

		//prints initial menu
		printf("\nWhich paycode would you like to use?\n\n"
							"1 Manager\n"
							"2 Hourly\n"
							"3 Commision\n"
							"4 Pieceworker\n\n"
							"enter -1 to exit\n");
		scanf("%d", &paycode);


		switch(paycode){

		//case for salary employees
		case 1:

			printf("What is the employees' annual salary?\n");
			scanf("%f", &salary);

			//calculates weekly pay based on the salary level and 52 weeks in a year
			weeklyPay = salary/52;

			printf("The employees weekly salary is %.2f\n", weeklyPay);

			break;

		//case for hourly employees
		case 2:

			//collects hours and payrate from user
			printf("How many hours did the employee work?\n");
			scanf("%f", &hours);

			printf("What is their payrate?\n");
			scanf("%f", &payrate);

			//computes their pay based on hours and payrate
			salary = hours*payrate;

			//calculates overtime
			if(hours > 40){
				overtime = hours - 40;
				salary = salary + (payrate/2  * overtime);
			}

			printf("The employees weekly pay is %.2f\n", salary);

			break;

		//case for commission based employees
		case 3:

			//prompts user for sales
			printf("What was the employees weekly sales?/n");
			scanf("%f", &sales);

			//salary based on sales and base pay
			commission = sales * .057;
			salary = commission + 250;

			printf("The employees weekly pay is %.2f/n", salary);
			break;

		//case for pieceworkers
		case 4:

			printf("How many items did the employee produce?\n");
			scanf("%d", &items);

			//calculates salary based on items sold
			salary = items*payPer;

			printf("The employees weekly pay is %.2f", salary);

			break;

		}//switch
	}//switch
	return 0;
}
