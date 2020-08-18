/*************************************************
**  Name: Manager.h
**  declares member functions for Manager.cpp
**  PostCondition:
        I)  creates 2 types of queues of orders 
**  PreCondition:
        I)  Manager creates orders    
*************************************************/
#ifndef ORDERS_H
#define ORDERS_H

#include <queue>
#include <string>

#include "Order.h"

class Orders
{
    private:
        queue <Order*> m_ordersUnfilled;
        queue <Order*> m_ordersToSee;
        queue <Order*> m_ordersCompleted;
        Order* m_pCurrentOrder;
    public:
        void addOrder(Order* order);
        void completeOrder();
        bool noMoreOrders();
        Order* getCurrentOrder();       // Only getter
        void loadOrders(string filename);
        void printOrders(ofstream& os);
};


#endif