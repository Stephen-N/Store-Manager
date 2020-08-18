/*************************************************
**  Name: Orders.cpp
**  constructs values for member variables and returns them
*************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Orders.h"

void Orders::addOrder(Order* order) 
{
    if (order->getOrderSeen() == false)
    {   
        // if (order->isAcceptParatial() == false) 
        // {  
        //     m_ordersToSee.push(order);
        // }
        m_ordersToSee.push(order);
        m_pCurrentOrder = m_ordersToSee.front();
    }
    
}

bool Orders::noMoreOrders()
{
    if (m_ordersToSee.empty() == false)
    {
        m_ordersToSee.pop();
        return false;
    }
    return true;
}

Order* Orders::getCurrentOrder()
{
    Order* current = m_ordersToSee.front();
    m_ordersCompleted.push(current);
    m_ordersToSee.pop();
    return current;
}

void Orders::loadOrders(string filename)
{
    ifstream fileIn;
    fileIn.open(filename);
    
    if (fileIn.is_open() == false)
    {
        cout << "fileIn Failed to open file" << endl;
        return;
    }

    // read input file to create orders and determine types
    string line = "";
    while (getline(fileIn, line))
    {
        string name , s_accept_partial, food_types, food_list = "";
        int name_length = 0;
        bool accept_partial = true;
        queue <FOOD_TYPE> requests;
        
        // gets name
        for (unsigned int i = 1; i < line.size(); i++)
        {
            if (line[i] != '\"')
            {
                name += line[i];  
            }
            else
            {
                name_length = i;
                break;
            }
        }

        line.erase(0, name_length + 2); // the +2 deletes the "" and following space
        
        istringstream filtered_line (line);
        filtered_line >> s_accept_partial;

        if (s_accept_partial == "no") 
        { 
            accept_partial = false; 
        }

        while (filtered_line >> food_types) 
        { 
            // series of ifs to determine food type
                if (food_types == "sweet") 
                {
                    food_types = "Sweet";
                    requests.push(Sweet);
                }
                else if (food_types == "starch")
                {
                    food_types = "Starch";
                    requests.push(Starch);
                }
                else if (food_types == "meat")
                {
                    food_types = "Meat";
                    requests.push(Meat);
                }
                else if (food_types == "vegetable")
                {
                    food_types = "vegetable";
                    requests.push(Vegetable);
                }
                else if (food_types == "fruit")
                {
                    food_types = "Fruit";
                    requests.push(Fruit);
                }
            //

            food_list += food_types + " ";
        }
        
        Order* order = new Order(name, accept_partial, requests, food_list);
        addOrder(order);
    }
}

void Orders::printOrders(ofstream& os)
{
    if (m_ordersCompleted.empty() == true)
    {
        os << "---------- Orders -----------" << endl;
        queue <Order*> temp = m_ordersToSee;
        while (temp.empty() == false)
        {
            Order* tempOrder = temp.front();

            os << tempOrder->getName() << endl;
            os << "Requests: " << tempOrder->getStringFoodRequests() << endl;
            os << "-----" << endl;
            temp.pop();
        }
        
        
    }
    else
    {
        while (m_ordersCompleted.empty() == false)
        {
            
            if (m_ordersCompleted.front()->getComplete() == false)
            {
                os << m_ordersCompleted.front()->getName() << " - Unable to complete order\n"
                    << "Unfilled Requests: " << endl;
                
                m_ordersCompleted.pop();
            }
            else
            {
                m_ordersCompleted.front()->printOrder(os);
                m_ordersCompleted.pop();
            }
            
            
        }
    }
    
        
    
    
}