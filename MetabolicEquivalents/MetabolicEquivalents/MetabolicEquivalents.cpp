/*
	MetabolicEquivalents.cpp 
	Comsc 140 -> C++
	Tyler Schulenberg
	March 18th, 2013
	The Program outputs the amount of calories burned after a specified workout for X amount of minutes.
	Each workout has a different metabolic rate (MET) determining the rate of calories burned in the formula.

*/

#include "stdafx.h"
#include <iostream>
using namespace std;

double calorieCalculator(int MET, int WEIGHT, int MINUTES);

 void main()
{

//Metabolic equivalents for the following activities (METS)
const int SLEEPING = 1;
const int WALKING = 2;	
const int BASKETBALL = 8;
//Input variables
int SELECTION = 0; //Activity selection
int WEIGHT;    //Weight in pounds (lbs)
int MINUTES;   //Time spent on activity
double CALORIES;

do {

  //Program main menu
  cout<<"\n";
  cout<<"Choose an activity from the following menu:\n";
  cout<<"1. Sleeping\n";
  cout<<"2. Walking (2 MPH)\n";
  cout<<"3. Basketball\n";
  cout<<"4. Exit\n\n";
  cout<<"Selection: ";
  cin>>SELECTION; //Activitiy selection
  cout<<"\n";

  cout<<"Please enter your weight in pounds\n";
  cin>>WEIGHT; //Weight selection
  cout<<"\n";

  cout<<"Finally enter the amount of minutes performing the selected activity\n";
  cin>>MINUTES; //Minute selection
  cout<<"\n";

switch (SELECTION) {

   //Calorie calculation and output for Sleeping
case 1:
	CALORIES = calorieCalculator(SLEEPING, WEIGHT, MINUTES);
	cout<<"Total calories burned:";
	cout<<CALORIES;
	cout<<"\n";
  break;

  //Calorie calculation and output for Walking
case 2:
	CALORIES = calorieCalculator(WALKING, WEIGHT, MINUTES);
	cout<<"Total calories burned:";
	cout<<CALORIES;
	cout<<"\n";
  break;

  //Calorie calculation and output for Basketball
case 3:
	CALORIES = calorieCalculator(BASKETBALL, WEIGHT, MINUTES);
	cout<<"Total calories burned:";
	cout<<CALORIES;
	cout<<"\n";
  break;
  
  //Exit case
case 4:
	break;

default:
	cout<<"Please enter a valid selection number\n\n";
  break;

}
} while ( SELECTION != 4 ); //Loop menu until exit is specified

}

double calorieCalculator(int MET, int WEIGHT, int MINUTES)
{
	double TEMP; //Holds MET formula calculation
	double TOTAL_CAL; //Holds final Calorie amount
	const double KG = 2.2;
	const double C1 = .0175;

	//MET equation
	TEMP = C1*MET*WEIGHT/KG;

	//Total Calories
	TOTAL_CAL = TEMP*MINUTES;

	return TOTAL_CAL;
}