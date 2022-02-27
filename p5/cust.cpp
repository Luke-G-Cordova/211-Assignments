// video.cpp
// Cordova, Luke
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
void Cust::print_enterStore(ostream& os){
    os << m_name << " entered store"<<endl;
}
void Cust::print_doneShopping(ostream& os){
    os << m_name << " done shopping"<<endl;
}
void Cust::print_startCheckout(ostream& os, int checker){
    os << m_name << " started checkout with checker " << checker <<endl;
}
void Cust::print_finishCheckout(ostream& os, int checker, int money){
    if(m_robber){
        os << m_name << " stole $" << money <<" and "<<m_items<<" item"<< ((m_items!=1)?"s":"") <<" to checker "<<checker<<endl;

    }else{
        os << m_name << " paid $" << 3*m_items <<" for "<<m_items<<" items to checker "<<checker<<endl;
    }
    
}
int Cust::getItems(){
    return m_items;
}
bool Cust::isRobber(){
    return m_robber;
}

