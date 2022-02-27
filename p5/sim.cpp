// video.cpp
// Cordova, Luke
#include <iostream>
#include <fstream>
#include "cust.h"
#include "pqueue.h"
using namespace std;

struct Checker{
    double reg_total;
    int break_time;
    Cust* cust;
};
void run_simulation(Pqueue& arrivalQ, int num_checkers, int break_duration, ostream& os);
bool legal_int(char* str);

int main(int argc, char* argv[]){
    int num_checkers = legal_int(argv[1]) ? atoi(argv[1]) : -1;
    int break_duration = legal_int(argv[2]) ? atoi(argv[1]) : -1;
    ifstream ifile(argv[3]);
    ofstream ofile(argv[4], ios::out);
    if(argc!=5)
        {cerr<<"Error: invalid number of command line arguments."<<endl;return 1;}
    if(!ifile)
        {cerr << "Error: could not open input file <" << argv[3] << ">." << endl;return 1;}
    if(!ofile)
        {cerr<<"Error: could not open output file <" << argv[4] << ">." << endl;return 1;}
    if(num_checkers < 1)
        {cerr<<"Error: invalid number of checkers specified."<<endl;return 1;}
    if(break_duration < 0)
        {cerr<<"Error: invalid checker break duration specified."<<endl;return 1;}
    
    Pqueue q;
    string name, type;
    int arrival, items;
    while(cin>>name){
        cin>>type;
        cin>>arrival;
        cin>>items;
        Cust* cust = new Cust(name, (type=="robber"), arrival, items);
        q.enqueue(cust, arrival);
    }
    
    run_simulation(q, num_checkers, break_duration, cout);

    return 0;
}

void run_simulation(Pqueue& arrivalQ, int num_checkers, int break_duration, ostream& os){
    Checker *checkers = new Checker[num_checkers];
    Pqueue shoppingQ;
    Pqueue checkingQ;
    for(int i = 0;i<num_checkers;i++){
        checkers[i].reg_total = 250;
        checkers[i].break_time = 0;
        checkers[i].cust = NULL;
    }
    int num_customers = arrivalQ.length();
    for(int clock = 1; num_customers > 0; clock++){
        // entering store
        while(arrivalQ.first_priority() == clock){
            Cust* cust = arrivalQ.dequeue();
            cust->print_enterStore(os);
            shoppingQ.enqueue(cust, clock + (cust->getItems()*2));
        }
        // done shopping
        while(shoppingQ.first_priority() == clock){
            Cust* cust = shoppingQ.dequeue();
            cust->print_doneShopping(os);
            checkingQ.enqueue(cust, 0);
        }
        // done checking
        for(int i = 0;i<num_checkers;i++){
            if(checkers[i].break_time == clock && checkers[i].cust != NULL){
                int money;
                if(checkers[i].cust->isRobber()){
                    money = checkers[i].reg_total;
                    checkers[i].reg_total = 0;
                    checkers[i].break_time = clock + break_duration;
                    
                }else{
                    checkers[i].reg_total += (3*checkers[i].cust->getItems());
                    money = (3*checkers[i].cust->getItems());
                }
                checkers[i].cust->print_finishCheckout(os, i, money);
                num_customers--;
                delete checkers[i].cust;
                checkers[i].cust = NULL;
            }
        }
        // assign customer to checker
        for(int i = 0;i<num_checkers;i++){
            if(
                checkers[i].break_time <= clock && 
                checkers[i].cust == NULL && 
                !checkingQ.empty()
            ){
                checkers[i].cust = checkingQ.dequeue();
                int offset = checkers[i].cust->isRobber() ? 7 : checkers[i].cust->getItems();
                checkers[i].break_time = clock + offset;
                checkers[i].cust->print_startCheckout(os, i);
            }
        }
    }
}
bool legal_int(char* str){
    int size = 0;
    while(*(str + size) != 0){
        if(!isdigit(*(str+size))){
            return false;
        }
        size++;
    }
    return true;
}