// video.cpp
// Cordova, Luke
#include <iostream>
#include "video.h"
#include "vlist.h"
using namespace std;


int main(){
    string title, url, comment;
    float length;
    int rating;
    Vlist vlist;
    string command;
    while(getline(cin, command)){
        if(command == "insert"){
            getline(cin, title);
            getline(cin, url);
            getline(cin, comment);
            cin >> length;
            cin >> rating;
            Video* video = new Video(
                title, url, comment, length, rating
            );
            if(!vlist.insert(video)){
                cerr << "Could not insert video <" << title << ">, already in list."<< endl;
            }
            cin.ignore();
        }else if(command == "print"){
            vlist.print();
        }else if(command == "length"){
            cout << vlist.getLength() << endl;
        }else if(command == "lookup"){
            getline(cin, title);
            Video* video = vlist.lookup(title);
            if(video!=NULL)video->print();
            else cerr << "Title <" << title << "> not in list." << endl;
        }else if(command == "remove"){
            getline(cin, title);
            if(!vlist.remove(title)){
                cerr << "Title <" << title << "> not in list, could not delete." << endl;
            }
        }else{
            cerr << "<" << command << "> is not a legal command, giving up." << endl;
            return 1;
        }
    }
    return 0;
}
