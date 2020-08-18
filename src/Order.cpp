/*************************************************
**  Name: Order.cpp
**  constructs values for member variables and returns them
*************************************************/
#include <iostream>
#include <fstream>

#include "Order.h"

Order::Order(string name, bool accept_partial, queue <FOOD_TYPE> requests, string foodList)
{
    m_sCustomerName = name;
    m_foodRequests = foodList;
    m_requests = requests;
    m_bAcceptsPartialOrder = accept_partial;
    m_bOrderCompleted = true;
    m_bOrderSeen = false;
}

void Order::setOrderComplete() 
{
    m_bOrderCompleted = false;
}

// GETTERS
FOOD_TYPE& Order::getNextRequest()
{
    FOOD_TYPE none = No_type;
    FOOD_TYPE& noMore = none;

    if (m_requests.empty() == true)
    {
        return noMore;
    }

    FOOD_TYPE& request = m_requests.front();
    m_requests.pop();

    return request;
}

bool Order::getOrderSeen()
{
    return m_bOrderSeen;
}

string Order::getName()
{
    return m_sCustomerName;
}

string Order::getStringFoodRequests()
{
    return m_foodRequests;
}

bool Order::getComplete()
{
    return m_bOrderCompleted;
}

bool Order::isAcceptParatial()
{
    return m_bAcceptsPartialOrder;
}

void Order::addFoodToOrder(Food* food)
{
    m_filledRequests.push(food);
}

Food* Order::popFoodFromOrder()
{
    Food* temp = m_filledRequests.front();
    m_filledRequests.pop();
    return temp;
}

void Order::printOrder(ofstream& os)
{
    double total = 0.0;
    os << "---------- Orders -----------" << endl;
    os << m_sCustomerName << endl;
    os << "Items: " << endl;
    while(m_filledRequests.empty() == false)
    {
        m_filledRequests.front()->printFood(os);
        os << " ";
        m_filledRequests.front()->printCost(os, total);
        os << endl;
        
        m_filledRequests.pop();
    }

    os << "***Total: $" << total << endl;
    os << "-----" << endl;
}