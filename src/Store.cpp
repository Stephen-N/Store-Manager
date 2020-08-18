/*************************************************
**  Name: Store.cpp
**  constructs values for member variables and returns them
*************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "Store.h"

void Store::addFood(Food* food)
{
    // series of ifs to see what type equals and add food to respective stacks
    if (food->getType() == Sweet) 
    {
        sweets.push(food);
        num_sweet++;
    }
    else if (food->getType() == Starch)
    {
        starches.push(food);
        num_starch++;
    }
    else if (food->getType() == Meat)
    {
        meats.push(food);
        num_meat++;
    }
    else if (food->getType() == Vegetable)
    {
        vegetables.push(food);
        num_vegetable++;
    }
    else if (food->getType() == Fruit)
    {
        fruits.push(food);
        num_fruit++;
    }
    else
    {
        cout << "There is no type" << endl;
    }
    
    
}

void Store::stockStore(string filename)
{
    ifstream fileIn;
    fileIn.open(filename);
    
    if (fileIn.is_open() == false)
    {
        cout << "fileIn Failed to open file" << endl;
        return;
    }

    // reads inputFile to fill food vector of store datamember
    string line = "";
    double cost = 0;
    int name_length = 0;
    FOOD_TYPE ftype = No_type;

    while (getline(fileIn, line))
    {
        // create a Food object from information line by line
        // need name, type, cost
        string name, type = "";

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
        filtered_line >> type;
        filtered_line >> cost; 

        // series of ifs to determine food type
            if (type == "sweet") 
            {
                ftype = Sweet;
            }
            else if (type == "starch")
            {
                ftype = Starch;
            }
            else if (type == "meat")
            {
                ftype = Meat;
            }
            else if (type == "vegetable")
            {
                ftype = Vegetable;
            }
            else if (type == "fruit")
            {
                ftype = Fruit;
            }
        //

        Food* newfood = new Food(name, ftype, cost);
        addFood(newfood);
    }

    // populate vector with stacks of separate types, calls makelist function
    m_bins.push_back(sweets);
    m_bins.push_back(starches);
    m_bins.push_back(meats);
    m_bins.push_back(vegetables);
    m_bins.push_back(fruits);
    
}

void Store::removeInventory(Order* current)
{
    // find what food to get
    FOOD_TYPE& foodToGetType = current->getNextRequest();

    while (foodToGetType != No_type)
    {
        Food* food;

        // get food from store and reduce the inventory
            if (foodToGetType == Sweet) 
            {
                if(m_bins[0].empty())
                {
                    // cout << "0 empty" << endl;
                    current->setOrderComplete();
                    return;
                }
                
                food = m_bins[0].top();
                m_bins[0].pop();
                num_sweet--;
            }
            else if (foodToGetType == Starch)
            {
                if(m_bins[1].empty())
                {
                    // cout << "1 empty" << endl;
                    current->setOrderComplete();
                    return;
                }
                
                food = m_bins[1].top();
                m_bins[1].pop();
                num_starch--;
            }
            else if (foodToGetType == Meat)
            {
                if(m_bins[2].empty())
                {
                    // cout << "2 empty" << endl;
                    current->setOrderComplete();
                    return;
                }
                
                food = m_bins[2].top();
                m_bins[2].pop();
                num_meat--;
            }
            else if (foodToGetType == Vegetable)
            {
                if(m_bins[3].empty())
                {
                    // cout << "3 empty" << endl;
                    current->setOrderComplete();
                    return;
                }

                food = m_bins[3].top();
                m_bins[3].pop();
                num_vegetable--;
            }
            else if (foodToGetType == Fruit)
            {
                if(m_bins[4].empty())
                {
                    // cout << "4 empty" << endl;
                    current->setOrderComplete();
                    return;
                }
                
                food = m_bins[4].top();
                m_bins[4].pop();
                num_fruit--;
            }
        //

        // cout << current->getName() << endl;
        current->addFoodToOrder(food);
        foodToGetType = current->getNextRequest();
        
    }
    
}

void Store::printStore(ofstream& os)
{
    stack <Food*> temp;

    os << "---------- Store ----------" << endl;
    os << "Meat: " << num_meat << " ";
    temp = m_bins[2];
    while (temp.empty() == false)
    {
        temp.top()->printFood(os);
        temp.pop();

        if (temp.empty() == false)
        {
            os << ", ";
        }
    }
    os << endl;

    os << "Fruit: " << num_fruit << " ";
    temp = m_bins[4];
    while (temp.empty() == false)
    {
        temp.top()->printFood(os);
        temp.pop();

        if (temp.empty() == false)
        {
            os << ", ";
        }
    }
    os << endl;

    os << "vegetable: " << num_vegetable << " ";
    temp = m_bins[3];
    while (temp.empty() == false)
    {
        temp.top()->printFood(os);
        temp.pop();

        if (temp.empty() == false)
        {
            os << ", ";
        }
    }
    os << endl;

    os << "Starch: " << num_starch << " ";
    temp = m_bins[1];
    while (temp.empty() == false)
    {
        temp.top()->printFood(os);
        temp.pop();

        if (temp.empty() == false)
        {
            os << ", ";
        }
    }
    os << endl;

    os << "Sweet: " << num_sweet << " ";;
    temp = m_bins[0];
    while (temp.empty() == false)
    {
        temp.top()->printFood(os);
        temp.pop();

        if (temp.empty() == false)
        {
            os << ", ";
        }
    }
    os << endl;
}
    