/*
	RedYellowGreen.cpp 
	Comsc 140 -> C++
	Tyler Schulenberg
	March 19th, 2013
	The computer generates a number between 100-999 then asks the user to guess the number. The computer responds with
	the number of red, yellow, and green digits of the guess.
	
	red = wrong integer guess
    green = correct integer
	yellow = correct integer, wrong placement

*/

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int compare(int RANDOM_NUM, int USER_NUM);
int one(int NUM);
int ten(int NUM);
int hundred(int NUM);
void output(int red, int green, int yellow);

void main(){

	int RANDOM_NUM;
	int USER_NUM = 1;
	int RESULT = 0;

	srand((unsigned)time(NULL));
	RANDOM_NUM = rand()%900+100; //generates random number between 100-999
	cout<<RANDOM_NUM<<endl;

	do{
	cout<<"enter a three digit number or 0 to exit\n";
	cin>>USER_NUM;
	RESULT = compare(RANDOM_NUM,USER_NUM);
	}while(RESULT == 0);

	system("pause");

}

//compare method takes both numbers and splits them into seperate arrays to compare
int compare(int RANDOM_NUM, int USER_NUM){
	
	int RANDOM[3];
	int USER[3];
	int red = 0, green = 0, yellow = 0;
	int RESULT = 0;
	
	RANDOM[0] = one(RANDOM_NUM);  //Random number made by computer is placed into random array
	RANDOM[1] = ten(RANDOM_NUM);
	RANDOM[2] = hundred(RANDOM_NUM);

	USER[0] = one(USER_NUM);      //Users number placed into user array
	USER[1] = ten(USER_NUM);
	USER[2] = hundred(USER_NUM);
	

	for (int x = 0; x < 3; x++){
		if((RANDOM[x] != USER[0]) && (RANDOM[x] != USER[1]) && (RANDOM[x] != USER[2])) //If number is not equal to any numbers
			red++;                                                                     //the number is marked as red
							   }

	for(int y = 0; y < 3; y++){             //checks each value with eachother for the green marker
		if(RANDOM[y] == USER[y])
			green++;
							  } 

	yellow = 3 - red - green; //calculates amount of yellow guessses

	output(red, green, yellow); //sends results to output method to display

	if(green == 3)
		RESULT = 1;

	return RESULT;

}

//seperates the one placement of the number for comparing
int one(int NUM){
	
	int temp;
	temp = NUM%10;
	return temp;

}

//seperates the ten placement of the number for comparing
int ten(int NUM){
	
	int temp;
	temp = NUM;
	temp = temp/10;
	temp = temp%10;
	return temp;

}

//seperates the hundred placement of the number for comparing
int hundred(int NUM){
	
	int temp;
	temp = NUM;
	temp = temp/100;
	temp = temp%10;
	return temp;

}

//output depending on the guess
void output(int red, int green, int yellow){
	
	if(green == 3)
		cout<<"Congratulations, you are correct!!!!!"<<endl; //winning output
	else
	{
	cout<<red<<"red\n";                       //normal guess output
	cout<<green<<"green\n";
	cout<<yellow<<"yellow\n";
	cout<<"Enter the next guess?\n";
	}   
}