/*************************************************
**  File    :   Driver.cpp
**  Project :   Project2, Store Manager and Order Filler
**  Author  :   Stephen Ndubueze
**  Date:   :   10/23/19
**  Section :   503
**  E-mail  :   sundubueze78@tamu.edu
**
**  This file contains the main driver program for Project2.
**  Summary: A store manager needs to build an organized store for his inventory 
		and then use that store to fill customer orders. Manager categorizes the 
		inventory by type and fills orders by the types of items that are requested. 
		If the store runs out of a certain type of item the customer can choose to 
		either accept the part of their order that can be filled or have their order 
		cancelled.
*************************************************/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "Manager.h"

using namespace std;

void printGreetings(ofstream& os);
int example(int z);

int main(int argc, char* argv[]) {
	ofstream outputFileStream;
	//open output file
	outputFileStream.open("results.txt");
	
	//print greeting
	printGreetings(outputFileStream);

	//take in store and order files
	Manager manager(argv[1], argv[2]);

	manager.printStatus(outputFileStream);

	manager.fillOrders(outputFileStream);

	manager.printStatus(outputFileStream);

	outputFileStream.close();

	return EXIT_SUCCESS;
	
}

void printGreetings(ofstream& os)
{
	os << "Stephen Ndubueze, Section 503" << endl;
}