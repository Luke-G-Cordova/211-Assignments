
#include <iostream>
#include "cust.h"
using namespace std;

Cust::Cust(string name, bool robber, int arrival, int items){
    m_name = name;
    m_robber = robber;
    m_arrival = arrival;
    m_items = items;
}

void Cust::print(ostream& os){
    os << m_name << (m_robber?" robber ":" shopper ");
    os << m_arrival << " " << m_items << endl;
}