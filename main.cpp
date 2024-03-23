#include <iostream>
#include <string>
#include "DisplayMenu.h"
#include "LinkedList.h"
#include <iomanip>
#include <limits>
#include <string.h>
using namespace std;


int main() {
    int menuChoice; //make a menuchoice var
    DisplayMenu m1; //create new objects
    LinkedList l1;
    int menuCtr = 0;

    string metalNames[] = {"turquoise", "coral", "gold", "copper"};
    int metalNamesLength = sizeof(metalNames) / sizeof(metalNames[0]);
    string *ptr = metalNames;
    bool validInput = false;

    do {
        if(menuCtr == 0) {
            m1.displayMenuFirstMsg();
            menuCtr++;
        }
        else {
            m1.displayMenuAfterMsg();
        }
        cin >> menuChoice; //get the user's menu choice
        //switch to handle the user's choice.
        string input = "";
        int input2;
        switch (menuChoice) {
            case 1: {
                cout << "Enter bead material: " << endl;
                cin >> input;
                while(!validInput) {
                    for(int i = 0; i < metalNamesLength; i++) {
                        int result = input.compare(*(ptr + i));
                        if(result == 0)  {
                            //this means strings are the same
                            validInput = true;
                            break;
                        }
                    }
                    cout << input << " is not a metal we carry...try again. " << endl;
                    cin >> input;
                }
                l1.appendList(input);
                break;
            }
            case 2: {
                cout << "Enter bead material: " << endl;
                cin >> input;
                while(!validInput) {
                    for(int i = 0; i < metalNamesLength; i++) {
                        int result = input.compare(*(ptr + i));
                        if(result == 0)  {
                            //this means strings are the same
                            validInput = true;
                            break;
                        }
                    }
                    cout << input << " is not a metal we carry...try again. " << endl;
                    cin >> input;
                }
                cout << "Enter Insert Position: " << endl;
                cin >> input2;
                l1.insertList(input,input2);
                break;
            }

            case 3: {

                break;
            }
            case 4: {

                break;
            }
            case 5: {

                break;
            }
            case 6: {
                //print exit statement
                cout << "Exiting..." << endl;
                cout << "Thanks for using the menu system and have a nice day." << endl;
                exit(0);
            }
            default: {
                //handle invalid menu option entries
                cout << "That Is Not A Valid Option, Please Choose An Option From The Numbered Menu Below: "
                     << endl;
                cout << endl;
                break;
            }
        }

    } while (menuChoice != 6); //continue presenting the menu until the user chooses to exit
    return 0;
}