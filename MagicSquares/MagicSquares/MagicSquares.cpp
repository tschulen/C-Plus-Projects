/*
    MagicSquares.cpp
    Comsc 140 -> C++
    Tyler Schulenberg
    May 8, 2013
    The program computes a magic square matrix and then displays it to the console
    default matrix sizes are hardcoded as 5 and 15
*/

#include "stdafx.h"
using namespace std;
#include <cmath>
#include <vector>
#include <iostream>
#include <stdio.h>

class Square
{
public:
	Square(int Size);
	void display();
	int computePlace(int Size, int Row, int Column);
private:
    vector<int> v;
	int Size;
};

int main()
{
	Square magic(5);
	magic.display();
	Square magics(15);
	magics.display();
	system("pause");
	return 0;
}

//computes each place of the matrix in order from left to right, top to bottom
//and places them in a vector
Square::Square(int length):Size(length)
{
	int Magic_Num;
	int loops = length+1;\
	for (int Row=1; Row<loops; Row++)
	{
		for(int Column=1; Column<loops; Column++)
		{
		Magic_Num = computePlace(length, Row, Column);
		v.push_back(Magic_Num);
		}
	}
}
// displays numbers in order going to a new line when the amount of numbers on one,
// is equal to n(size of the matrix)
void Square::display()
{
	int formatcount=0;
	for(int i=0; i < v.size(); i++)
	    {
	        cout << v[i]<<" ";
	        formatcount++;
	        if(formatcount == Size)
	            {
	            	cout<< endl;
		            formatcount=0;
            	}
    	}
}

// to compute each int, I used the algorithm
// F(n) = n((I + J - 1 + Floor(n/2))mod n) +((I + 2J - 2) mod n) + 1    
// I = row number
// J = column number
int Square::computePlace(int size, int Row, int Column)
{
		double converter, FLOOR;
		int Magic_Num;
		int intconverter;
        // the following code is the above algorithm broken down
			converter = double(size); 
			FLOOR = floor(converter/2);
			intconverter = int(FLOOR);
			int aStep =(Row+Column-1+intconverter);
			Magic_Num = size*(aStep% size) + ((Row +2*Column-2) % size)+1;
			return Magic_Num;
}