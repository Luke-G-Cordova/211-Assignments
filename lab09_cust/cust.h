
#ifndef CUST_H
#define CUST_H
#include <iostream>
using namespace std;

class Cust{
    public:
        Cust(string name, bool robber, int arrival, int items);
        void print(ostream& os);
    private:
        string m_name;
        bool m_robber;
        int m_arrival;
        int m_items;
};
#endif