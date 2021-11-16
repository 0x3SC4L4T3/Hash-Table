#include "Hash.h"
#include <iostream>
#include <sstream>
#include <string>


using namespace std;

//This function extracts tokens from oneLine and get all info. of a Food
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price);

//This function extracts tokens from oneLine and get a Food key which is
//the combination of FoodID, name and supplierID
void getKey(string oneLine, string& FoodID, string& name, string& supplierID);

int main()
{
	//a variable represents the number of hash table slots
	int size;

	//a variable represents the number of commands
	int numOfCommand;

	//a variable represents the actual command name
	string command;

	string FoodID, name, supplierID;
	double price;
	string delimiter = ",";
	string oneLine;
	//declare any other necessary variables here
   //----

	cout << "Enter the size of the hash table: ";
	cin >> size;
	cin.ignore(20, '\n');

	//create the hash table with the relevant number of slots
	 //----
	Hash hashTable(size);
	do {
		cout << "\nEnter food info.(enter InsertionEnd to terminate): " << endl;
		getline(cin, oneLine);
		if (oneLine.compare("InsertionEnd") == 0)
			break;

		//if command is not InsertionEnd
		//Get one line, call getFoodInfo(), then
		getFoodInfo(oneLine, FoodID, name, supplierID, price);
		//insert the new Food inside the hash table
		//----
		hashTable.hashInsert(FoodID, name, supplierID, price);

	} while (true);

	cout << endl;
	cout << "Enter number of commands: \n";
	cin >> numOfCommand;
	cin.ignore(20, '\n');

	for (int i = 0; i < numOfCommand; i++)
	{
		//get one line from the input file and extract the first token,

		//-----
		cout << "Enter command: \n";
		getline(cin, oneLine);
		string delimiter = ",";
		int pos = oneLine.find(delimiter);
		string token = oneLine.substr(0, pos);
		string command = token;
		oneLine.erase(0, pos + delimiter.length());

		//if the token is hashDisplay, call the relevant function in Hash.h
		if (command.compare("hashDisplay") == 0) {
			hashTable.hashDisplay();
		}

		//if the token is hashSearch, call the relevant function in Hash.h
//----
		else if (command.compare("hashSearch") == 0) {
			getKey(oneLine, FoodID, name, supplierID);
			hashTable.hashSearch(FoodID, name, supplierID);
		}
		//if the token is hashDelete, call the relevant function in Hash.h
		//----
		else if (command.compare("hashDelete") == 0) {
			getKey(oneLine, FoodID, name, supplierID);
			hashTable.hashDelete(FoodID, name, supplierID);
		}
		//for all other cases, show the following message
		else {
			cout << "Invalid command" << endl;
		}




	} //end for loop

	system("pause");
	return 0;
} //end main

//*******************************************************************
//This function extract the tokens from one line and
//get all Food info.
//*******************************************************************
void getFoodInfo(string oneLine, string& FoodID, string& name, string& supplierID, double& price)
{
	string delimiter = ",";
	int pos = oneLine.find(delimiter);
	string token = oneLine.substr(0, pos);
	FoodID = token;
	oneLine.erase(0, pos + delimiter.length());

	pos = oneLine.find(delimiter);
	token = oneLine.substr(0, pos);
	name = token;
	oneLine.erase(0, pos + delimiter.length());

	pos = oneLine.find(delimiter);
	token = oneLine.substr(0, pos);
	supplierID = token;
	oneLine.erase(0, pos + delimiter.length());

	pos = oneLine.find(delimiter);
	token = oneLine.substr(0, pos);
	price = stod(token);
	oneLine.erase(0, pos + delimiter.length());
	//finish the remaining codes below
	//----
	//----

	//Note: you can use stod to convert a string into double
	//but you will need c++11 compiler to achieve this
	//for example: price = stod(token);
}

//********************************************************************
//This function extracts the FoodID, name, supplierID from a given line
//These info. forms the key of a Food.
//This function is given to you. Study it.
//********************************************************************
void getKey(string oneLine, string& FoodID, string& name, string& supplierID)
{
	string delimiter = ",";
	int pos = oneLine.find(delimiter);
	string token = oneLine.substr(0, pos);
	FoodID = token;
	oneLine.erase(0, pos + delimiter.length());

	pos = oneLine.find(delimiter);
	token = oneLine.substr(0, pos);
	name = token;
	oneLine.erase(0, pos + delimiter.length());

	pos = oneLine.find(delimiter);
	token = oneLine.substr(0, pos);
	supplierID = token;
	oneLine.erase(0, pos + delimiter.length());
}