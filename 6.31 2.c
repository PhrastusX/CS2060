/*CS 2060
Author: Theo Diehl
Created on: Jul 11, 2020
Assingment: 6.31.c
Tests to see if an input is a palindrome
*/

#include <stdio.h>

int testPalindrome(char array[], int length, int start);
void String(char str[]);


int main(void){

	char str[200];//initializes string

	String(str);

}//main


//function to test for palindromes
int testPalindrome(char array[], int length, int start){



	int a = start;//default starts at 0
	int b = length;//the length of the string

	//skips the comparing of spaces
	if (array[a] == ' '){
		a++;
	}
	if (array[b] == ' '){
		b--;
	}

	//base case when a is greater than b
	if (a >= b){
		return 1;
	}
	//tests if a and b do not equal each other
	if(array[a] == array[b]){

		return testPalindrome(array, b-1, a+1);//if it gets to base case returns 1
	}//if
	else{
		return 0;//if it did not make it to base case returns 0
	}



}//testPalindrome()

//gives the user directions and stores their input.
void String(char str[]){


		puts("What word or sentence would you like to test for palindromes? ");

		//gets a string and stores it in str[]
		scanf("%199[^\n]s", str);

		//gets length of string
		int length = strlen(str);


		int i = testPalindrome(str, length -1, 0);


		printf("%d\n\n", i);

}//String()
