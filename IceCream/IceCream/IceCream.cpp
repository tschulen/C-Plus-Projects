/*
	IceCream.cpp 
	Comsc 140 -> C++
	Tyler Schulenberg
	March 18th, 2013
	User specifies specifics for an ice cream cone, program totals bill and make cone.
*/

#include "stdafx.h"
#include <iostream>
using namespace std;

int intro();
double total_bill(int TOTAL_CONES, double TOTAL_SCOOPS);
void pricelist();
double scoop(double CONES);

 void main()
{
	int TOTAL_CONES = 0;
	double FINAL_PRICE;
	double TOTAL_SCOOPS;

	pricelist();

	
	TOTAL_CONES = intro();
	

	TOTAL_SCOOPS = scoop(TOTAL_CONES);

	FINAL_PRICE = total_bill(TOTAL_CONES, TOTAL_SCOOPS);
	cout<<"Total charge: $" << FINAL_PRICE;
	system("pause");
}

//greeting message + check to make sure valid cones entered
int intro(){
	int CONES;
	cout<<"Ice Cream Flavors: Only one input character for each flavor.\n";
	cout<<"Please input the number of cones that you wish to purchase (10 max):\n";
	cin>>CONES;
	if ( (CONES > 11) || (CONES < 1) )
		intro();
	return CONES;
}

//price of Ice cream given scoops and cones
double total_bill(int TOTAL_CONES, double SCOOPS){
	double TOTAL_SCOOPS;
	double TOTAL_PRICE;
	double ADD_PRICE;
	double TEMP;
	
	TOTAL_SCOOPS = TOTAL_CONES * SCOOPS;
	
	if (TOTAL_SCOOPS = 1.0)
		TOTAL_PRICE = 2.00;
	if (TOTAL_SCOOPS = 2.0)
		TOTAL_PRICE = 3.00;
	if (TOTAL_SCOOPS > 2.0){
		TEMP = TOTAL_SCOOPS - 2.0;
		ADD_PRICE = TEMP * 0.75;
		TOTAL_PRICE = 2.00 + ADD_PRICE;
	} 

	
	return TOTAL_PRICE;
}

void pricelist(){

	cout<<"Ice Cream vendor price list:\n";
	cout<<"1 scoop ->            $2.00\n";
	cout<<"2 scoop ->            $3.00\n";
	cout<<"each scoop after 2 -> $0.75\n";

}

double scoop(double CONES){

	char FLAVORS[11];
	double SCOOPS;
	//asks for amount of scoops
	for (int x = 1; x < CONES+1; x++){
		cout<<"Cone #";
		cout<<x;
		cout<<"\n";
		cout<<"How many scoops for the cone?\n";
	    cin>>SCOOPS;
		//gathers flavors for output
		for( int y = 1; y < SCOOPS+1; y++){

            cout<<"Specify the flavor for scoop " << y << ":\n";
			cin>>FLAVORS[y];
		}
		//makes cone
		cout<<"Here is your cone! Enjoy!!!!\n"; 
		for (int z = 1; z < SCOOPS+1; z++){
			cout<< "(" << FLAVORS[z] << ")\n";
		}

		cout<<"\ /" << "\n";
		cout<<" |\n";

	}
	return SCOOPS;
}