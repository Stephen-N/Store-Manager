/*************************************************
**  Name: Store.h
**  declares member functions for Store.cpp
**  PreCondition:
        I)  called by manager to be created and stocked
*************************************************/
#ifndef STORE_H
#define STORE_H

#include <vector>
#include <stack>

#include "Food.h"
#include "Order.h"

using namespace std;

class Store
{
    private:
        vector<stack <Food*>> m_bins; // each stack represents a food type
        stack <Food*> sweets;
        stack <Food*> starches;
        stack <Food*> meats;
        stack <Food*> vegetables;
        stack <Food*> fruits;
        int num_meat = 0;
        int num_fruit = 0;
        int num_vegetable = 0;
        int num_starch = 0;
        int num_sweet = 0;

    public:
        void addFood(Food* food);
        Food* getFoodByType(FOOD_TYPE f_type); // Only getter
        void stockStore(string filename);
        void removeInventory(Order* current);
        void printStore(ofstream& os);

};


#endif