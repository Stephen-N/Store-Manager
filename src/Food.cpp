/*************************************************
**  Name: Food.cpp
**  constructs values for member variables and returns them
*************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

#include "Food.h"

Food::Food(string name, FOOD_TYPE type, double cost)
{
    m_sName = name;
    m_eType = type;
    m_dCost = cost;
}

FOOD_TYPE Food::getType()
{
    return m_eType;
}

void Food::printFood(ofstream& os)
{
    os << m_sName;
}

void Food::printCost(ofstream& os, double& total)
{
    os << fixed << setprecision(2);
    os << "$"<< m_dCost;
    total += m_dCost;
}