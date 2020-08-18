/*************************************************
**  Name: Manager.cpp
**  constructs values for member variables and returns them
*************************************************/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "Manager.h"

using namespace std;

Manager::Manager (char* store, char* orders) // constructor
{
    // cout << store << endl;
    // cout << orders << endl;
    createStore(store);
    createOrders(orders);
}
void Manager::createStore (string filename) // creates initial store instance
{
    // cout << filename << endl;
    m_store.stockStore(filename);
}

void Manager::createOrders (string filename) // creates list of initial orders
{
    m_orders.loadOrders(filename);
}

void Manager::fillOrders (ofstream& os) // Passes current orders to store and removes inventory
{
    
    Order* current = m_orders.getCurrentOrder();
    m_store.removeInventory(current);
    if (m_orders.noMoreOrders() == false)
    {
        this->fillOrders(os);
    }
}

void Manager::printStatus (ofstream& os)
{
    m_store.printStore(os);
    m_orders.printOrders(os);
}