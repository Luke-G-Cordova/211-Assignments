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
void recursive_sort(Pqueue &q);
bool legal_int(char* str);

int main(int argc, char* argv[]){
    if(argc!=5)
        {cerr<<"Error: invalid number of command line arguments."<<endl;return 1;}
    int num_checkers = legal_int(argv[1]) ? atoi(argv[1]) : -1;
    int break_duration = legal_int(argv[2]) ? atoi(argv[2]) : -1;
    ifstream ifile(argv[3]);
    ofstream ofile(argv[4], ios::out);
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
    while(ifile>>name){
        ifile>>type;
        ifile>>arrival;
        ifile>>items;
        Cust* cust = new Cust(name, (type=="robber"), arrival, items);
        q.enqueue(cust, arrival);
    }
    
    run_simulation(q, num_checkers, break_duration, ofile);

    return 0;
}

void run_simulation(Pqueue& arrivalQ, int num_checkers, int break_duration, ostream& os){
    Checker *checkers = new Checker[num_checkers];
    Pqueue shoppingQ;
    Pqueue *checkingQ = new Pqueue[num_checkers];
    for(int i = 0;i<num_checkers;i++){
        checkers[i].reg_total = 250;
        checkers[i].break_time = 0;
        checkers[i].cust = NULL;
    }
    int num_customers = arrivalQ.length();
    int clock;
    for(clock = 1; num_customers > 0; clock++){
        // entering store
        while(arrivalQ.lowest_priority() == clock){
            Cust* cust = arrivalQ.dequeue();
            cust->print_enterStore(os, clock);
            shoppingQ.enqueue(cust, clock + (cust->getItems() * 2));
        }
        // done shopping
        while(shoppingQ.lowest_priority() != -1 && shoppingQ.lowest_priority() <= clock){
            
            Pqueue *cq;
            Checker *cc;
            bool startWith = true;
            for(int i = 0;startWith&&i<num_checkers;i++){
                if(checkers[i].break_time <= clock){
                    cq = &checkingQ[i];
                    cc = &checkers[i];
                    
                    startWith = false;
                    int check = 0;
                    for(int j = i;j<num_checkers;j++){
                        if(
                            (cq->length()+(cc->cust!=NULL?1:0) > checkingQ[j].length() + (checkers[j].cust!=NULL?1:0)) && 
                            checkers[j].break_time <= clock
                        ){
                            cq = &checkingQ[j];
                            cc = &checkers[j];
                            check = j;
                        }
                    }
                    Cust* cust = shoppingQ.dequeue();
                    cout<<check<<endl;
                    cust->print_doneShopping(os, clock, check);
                    cq->enqueue(cust, 0);
                }
            }
        }
        // done checking
        for(int i = 0;i<num_checkers;i++){
            
            if(checkers[i].break_time <= clock && checkers[i].cust != NULL){
                int money;
                if(checkers[i].cust->isRobber()){
                    money = checkers[i].reg_total;
                    checkers[i].reg_total = 0;
                    checkers[i].break_time = clock + break_duration;
                }else{
                    checkers[i].reg_total += (3*checkers[i].cust->getItems());
                    money = (3*checkers[i].cust->getItems());
                }
                checkers[i].cust->print_finishCheckout(os, clock, i, money);
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
                !checkingQ[i].empty()
            ){
                
                checkers[i].cust = checkingQ[i].dequeue();
                
                // if robber offset = 7 else offset = customers item count
                int offset = checkers[i].cust->isRobber() ? 7 : checkers[i].cust->getItems();
                checkers[i].break_time = clock + offset;
                checkers[i].cust->print_startCheckout(os, clock, i);
            }
        }
    }
    for(int i = 0;i<num_checkers;i++){
        os<<"registers["<<i<<"] = $"<<checkers[i].reg_total<<endl;
    }
    os<<"time = "<<clock<<endl;
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
void recursive_sort(Pqueue &q){
    if(!q.empty()){
        int hold_priority;
        Cust* cust = q.dequeue(hold_priority);
        recursive_sort(q);
        q.enqueue(cust, hold_priority);
    }
}