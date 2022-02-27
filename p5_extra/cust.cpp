// video.cpp
// Cordova, Luke
#include <iostream>
#include <assert.h>
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
void Cust::print_enterStore(ostream& os, int clock){
    assert(clock == m_arrival);
    os << clock <<": " << m_name << " entered store"<<endl;
}
void Cust::print_doneShopping(ostream& os, int clock, int checker){
    os << clock <<": " << m_name << " done shopping, waiting for checker "<< checker <<endl;
}
void Cust::print_startCheckout(ostream& os, int clock, int checker){
    os << clock <<": " << m_name << " started checkout with checker " << checker <<endl;
}
void Cust::print_finishCheckout(ostream& os, int clock, int checker, int money){
    if(m_robber){
        os << clock << ": " << m_name << " stole $";
        os << money << " and " << m_items << " item";
        os << ((m_items!=1)?"s":"") << " from checker " << checker << endl;

    }else{
        os << clock << ": " << m_name << " paid $";
        os << 3*m_items << " for " << m_items <<" item";
        os << ((m_items!=1)?"s":"") << " to checker " << checker << endl;
    }
    
}
int Cust::getItems(){
    return m_items;
}
bool Cust::isRobber(){
    return m_robber;
}

