
/*
	MoneyCounterSimulation.cpp 
	Comsc 140 -> C++
	Tyler Schulenberg
	March 18th, 2013
    Counter that allows you to manipulate it by a-cents, s-dimes, d-dollars, and f-tens of dollars
    Allows you to set a count limit and checks to see if you go over the designated amount
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Counter
{
  public:
	Counter();
	//Initializes ones to 0
	Counter(int max_Count);
	//Initializes all values to arguements
	void reset();
	void incre1(int num);
	void incr10(int num);
	void incr100(int num);
	void incr1000(int num);
	void display();
    bool overflow();
  
private:
	  int total;
	  int max;

};

int main()
	{
		Counter Count1;
		
		char CHAR_INPUT = 'a';
		int INT_INPUT;
		int SIZE_INPUT =9999;

		Count1.display();
		while (CHAR_INPUT != 'e')
		{
		    cin>> CHAR_INPUT >> INT_INPUT;
		
		    switch(CHAR_INPUT)
		    {
			    case 'a': // ones
			    	Count1.incre1(INT_INPUT);
			    	Count1.display();
			    	break;
			    case 's': // tens
			    	Count1.incr10(INT_INPUT);
			    	Count1.display();
			    	break;
			    case 'd': //hundreds
			    	Count1.incr100(INT_INPUT);
			    	Count1.display();
			    	break;
		    	case 'f': //thousdands
			    	Count1.incr1000(INT_INPUT);
		    		Count1.display();
		    		break;
		    	case 'n': // new counter
		    		cout<<"what is the desired size between 0 and 9999?"<< endl;
		    		cin >> SIZE_INPUT;
		    		Count1 = Counter(SIZE_INPUT);
		    		Count1.display();
		    		break;
		    	case'o': // overflow
		    		bool over;
		    		over = Count1.overflow();
		    		if (over ==true)
		    			cout << "\nYou have gone over your desired amount!!!"<< endl;
		    		else
		    			cout <<"\nNo overflow"<<endl;
		    		Count1.display();
		    		break;
			    default:
			    		cout << "Please enter characters in given format."<< endl;
			    		Count1.display();
			    		break;
		       }
		 }
		return 0;

	}

    //display menu
	void Counter::display()
	{
		cout<< endl <<"Maximum value of the counter is "<< max << "." <<endl;
		cout<<"Current value of the counter is "<< total << "." <<endl;
		cout<<"Enter a key, either a,s,d,f, followed by 1-9, or o for overflow"<<endl;
		cout<<"A->cents, s->dimes, d->dollars, f-> dollars"<< endl;
		cout<<"To start a fresh counter with a chosen max less type n1" << endl;
		cout<<"To exit type e1"<< endl;
		cout<<"To check for overload type o1" << endl;
	}
    //resets the counter
	void Counter::reset()
	{
		total = 0;
	}
	//increments the ones digit
	void Counter::incre1(int num)
	{
		int ones = 1;
		int tot = num * ones;
		total = total + tot;
	}
    //increments the tens digit
	void Counter::incr10(int num)
	{
		int tens = 10;
		int tot = num* tens;
		total = total + tot;
	}
    //increments the hundreds digit
	void Counter::incr100(int num)
	{
		
		int hundreds = 100;
		int tot = num* hundreds;
		total = total + tot;
	}
    //increments the thousands digit
	void Counter::incr1000(int num)
	{
		
		int thousands = 1000;
		int tot = num* thousands;
		total = total + tot;
	}
    //detects if the counter has gone over the max value and displays overflow if so
bool Counter::overflow()
	{
		bool d;
		if(total > max)
		{
			cout<<"o\n";
			d=true;
		}
		else
			d=false;

		return d;
	}


Counter::Counter(int max_Count):max(max_Count),total(0)
{ 

}
Counter::Counter():total(0), max(9999)
{

}

