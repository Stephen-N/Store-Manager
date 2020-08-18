/*************************************************
**  Name: Manager.h
**  declares member functions for Manager.cpp
**  PostCondition:
        I)  creates 1 instance of a Store and set of orders
        II) prints the results of the orders to a file
**  Questions:
        1) What should the  fillOrders function do
*************************************************/
#ifndef MANAGER_H
#define MANAGER_H

#include "Store.h"
#include "Orders.h"

class Manager
{
    private:
        Store m_store;
        Orders m_orders;
    
    public:
        Manager(char* store, char* orders); // constructor
        void createStore(string filename);
        void createOrders(string filename);
        void fillOrders(ofstream& os);
        void printStatus(ofstream& os);
        
};


#endif