// video.cpp
// Cordova, Luke
#ifndef CUST_H
#define CUST_H
#include <iostream>
using namespace std;

class Cust{
    public:
        Cust(string name, bool robber, int arrival, int items);
        void print(ostream& os);
        void print_enterStore(ostream& os, int tstamp);
        void print_doneShopping(ostream& os, int tstamp, int checker);
        void print_startCheckout(ostream& os, int tstamp, int checker);
        void print_finishCheckout(ostream& os, int tstamp, int checker, int money);
        int getItems();
        bool isRobber();
    private:
        string m_name;
        bool m_robber;
        int m_arrival;
        int m_items;
};
#endif