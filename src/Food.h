/*************************************************
**  Name: Food.h
**  declares member functions for Food.cpp
**  PostCondition:
        I)  creates parameters for food for Store class
**  PreCondition:
		I) 	created when store is created by manager
*************************************************/
#ifndef FOOD_H
#define FOOD_H

#include <string>

using namespace std;
enum FOOD_TYPE{Sweet, Starch, Meat, Vegetable, Fruit, No_type};

class Food
{
	private:
		string m_sName = "";
		FOOD_TYPE m_eType = No_type;
		double m_dCost = 0.0;

	public:
		Food(string name, FOOD_TYPE type, double cost); // constructor
		
		// getters
		FOOD_TYPE getType();
		void getName();
		
		void printFood(ofstream& os);
		void printCost(ofstream& os, double& total);
    
};



#endif