/*************************************************
**  Name: Manager.h
**  declares member functions for Manager.cpp
**  PostCondition:
        I)  creates 1 instance of a Store and set of orders
        II) prints the results of the orders to a file
**  Questions:
        1) What should the  fillOrders function do
*************************************************/
#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <queue>

#include "Food.h"

using namespace std;

class Order
{
    private:
        string m_sCustomerName;
        string m_foodRequests;
        queue <FOOD_TYPE> m_requests;
        bool m_bAcceptsPartialOrder;
        bool m_bOrderCompleted;
        bool m_bOrderSeen;
        queue <Food*> m_filledRequests; // food that was successfully ordered
    public:
        Order(string name, bool accept_partial, queue <FOOD_TYPE> requests, string foodList); // constructor

        // Setters
        void setCustomerName(string name);
        void setAcceptPartial(bool acceptP);
        void setOrderComplete();

        
        // getters
        FOOD_TYPE& getNextRequest();
        bool getOrderSeen();
        string getName();
        string getStringFoodRequests();
        bool getComplete();

        bool isAcceptParatial();
        void addRequestToOrder(FOOD_TYPE f_type);
        void addFoodToOrder(Food* food); // Food that is taken from store inventory
        Food* popFoodFromOrder();

        void printOrder(ofstream& os);


};


#endif