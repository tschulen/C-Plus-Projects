/*	
	Dictionary.cpp
	Comsc 140 -> C++
	Tyler Schulenberg
	May 8, 2013
	The program loads a list of words from a file with the format "word\n word\n"
	It takes the unique words and loads them to a set to be added/deleted/compared 
*/


#include "stdafx.h"
#include <string>
#include <iostream>
#include <cctype>
#include <set>
#include <fstream>
using namespace std;

string make_Lower(const string& s);
void printList(set<string>& s, set<string>::const_iterator& position);
void addWord(string input, set<string>& s);
void deleteWord(string input, set<string>& s);
void findWord(string input, set<string>& s);
int optionsMenu();

int main()
{
	set<string> s;
	int Option= 1;
	set<string>::const_iterator position;
    string line; //this will contain the data read from the file
    ifstream myfile ("Dictionary.txt"); //opening the file.
	
    if (myfile.is_open()) //if the file is open
    {
        while (! myfile.eof() ) //while the end of file is NOT reached
        {
            getline (myfile,line); //get one line from the file
			string lower = make_Lower(line);
			s.insert(lower);
        }
        myfile.close(); //closing the file
    }

	
while(Option != 0){	
	Option = optionsMenu();
	string wChoice = " ";
	switch (Option)
      {
         case 1: //option for adding a word
			cout << "Type in desired word" << endl;
			cin>>wChoice;
			addWord(wChoice, s);
            break;
         case 2://option for deleting a word
			cout << "Type in desired word" << endl;
			cin>>wChoice;
			deleteWord(wChoice, s);
            break;
         case 3: //option for finding a word
			cout << "Type in desired word" << endl;
			cin>>wChoice;
			findWord(wChoice, s);
            break;
		 case 4: //option for printing the set
			 printList(s, position);
		 case 0:
			 // exit
			 break;
		 default:
			 cout << "Invalid choice, please pick again\n";
			 break;
      }
}
	system("PAUSE");
    return 0;
	
} 
//iterator goes through list and prints it out in order
void printList(set<string>& s, set<string>::const_iterator& position)
{
	
	for (position = s.begin(); position !=s.end(); position++)
		cout << *position << endl;
	cout << endl << endl;
}

//Uses <cctype> and <string>
//makes all characters in the given string of lower value
string make_Lower(const string& s)
{
	string temp(s);
	for (int i = 0; i < s.length(); i++)
		temp[i] = tolower(s[i]);

	return temp;
}

// adds typed in word to the set
void addWord(string input, set<string>& s)
{
	set<string>::const_iterator p;
	string lower = make_Lower(input); 
	p = s.find(lower);

	if(p == s.end())
		{
			cout << "The inputed word does not exist in the dictionary\n" << endl;
			s.insert(lower);
		}
	else
		cout << "The inputed word already exists in the dictionary\n" << endl;
}

//checks to see if word is in dictionary 
// if so deletes it
void deleteWord(string input, set<string>& s)
{
	set<string>::const_iterator p;
	string lower = make_Lower(input); 
	p = s.find(lower);

	if(p == s.end())
		cout << "The inputed word does not exist in the dictionary\n" << endl;
	else
		s.erase(*p);
}
// checks to see if word is in the set
void findWord(string input, set<string>& s)
{
	set<string>::const_iterator p;
	string lower = make_Lower(input); 
	p = s.find(lower);

	if(p == s.end())
		cout << "The inputed word does not exist in the dictionary\n" << endl;
	else
		cout << "The inputed word exists in the dictionary\n" << endl;
}
//easy call to options menu
int optionsMenu()
{
	cout << "Dictionary Menu:" << endl;
	cout << "1) Add Word" << endl << "2) Delete Word" << endl << "3) Verify Word" << endl;
	cout << "4) Display List" << endl;
	cout << "0) Exit" << endl << "Type in the number of the option you wish to proceed"<< endl;
	int choice=0;
	cin>>choice;
	return choice;
}
