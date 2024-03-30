//
// Created by Kareem Nabulsi on 3/21/24.
//

#include "DisplayMenu.h"
#include <iostream>
#include <cctype>

using namespace std;

//separated this for organization
void DisplayMenu::displayMenuFirstMsg() {
    cout << "This Menu Will Only Show Up Once:" << endl;
    cout << "**** LinkedList Menu ****" << endl;
    cout << "1.  Append" << endl;
    cout << "2.  Insert" << endl;
    cout << "3.  Delete" << endl;
    cout << "4.  Print" << endl;
    cout << "5.  Search" << endl;
    cout << "6.  Exit" << endl;
    cout << endl;
    cout << "Please Enter Your Menu Choice: ";
    cout << endl;
}

void DisplayMenu::displayMenuAfterMsg() {
    cout << "**** LinkedList Menu ****" << endl;
    cout << "Please Enter Your Menu Choice: ";
    cout << endl;
}


void DisplayMenu::toLowerCase(string &str) {
    for (int i = 0; i < str.length(); i++) {
        //iterate through each char and use tolower method
        str[i] = tolower(str[i]);
    }
}
