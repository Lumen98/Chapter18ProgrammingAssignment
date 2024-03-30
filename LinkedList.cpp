//
// Created by Lumen on 3/21/24.
//

#include "LinkedList.h"
#include <iostream>

using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    index = 0;
}

void LinkedList::appendList(string &str) {
    //high level validation
    bool validInput = false;
    string metalNames[] = {"turquoise", "coral", "gold", "copper"};
    int metalNamesLength = sizeof(metalNames) / sizeof(metalNames[0]);
    string *ptr = metalNames;
    while (!validInput) {
        cout << str << endl;
        for (int i = 0; i < metalNamesLength; i++) {
            if (str == *(ptr + i)) {
                //this means strings are the same
                validInput = true;
                break;
            }
        }
        if (validInput == true) {
            break;
        }
        cout << str << " is not a metal we carry...try again. " << endl;
        return;
    }

    //create new node with string input value
    Node *newNode = new Node(str);
    //if list is empty
    if (head == nullptr) {
        head = newNode; //have head point to the first node
        cout << "Thank you - a " << str << " bead has been added to your necklace at position " << index << "." << endl;
        return;
    }
    //create temp
    Node *tempNode = head;
    //as long as there are still nodes in the list
    while (tempNode->next != nullptr) {
        tempNode = tempNode->next; //iterate tempnode to get to the end of the list
    }
    index++;
    //set temp node to point to the new node --> new node is pointing to null by default
    tempNode->next = newNode;
    cout << "Thank you - a " << str << " bead has been added to your necklace at position " << index << "." << endl;
}

int LinkedList::insertList(string &str, int &num) {
    //high level validation
    bool validInput = false;
    string metalNames[] = {"turquoise", "coral", "gold", "copper"};
    int metalNamesLength = sizeof(metalNames) / sizeof(metalNames[0]);
    string *ptr = metalNames;
    while (!validInput) {
        cout << str << endl;
        for (int i = 0; i < metalNamesLength; i++) {
            if (str == *(ptr + i)) {
                //this means strings are the same
                validInput = true;
                break;
            }
        }
        if (validInput == true) {
            break;
        }
        cout << str << " is not a metal we carry...try again. " << endl;
        return -1;
    }
    int position = 1;
    //if list is empty
    if (head == nullptr) {
        return -1;
    }
    //instantiate node objects
    Node *newNode = new Node(str);
    Node *leftNode = head;
    Node *rightNode = head;
    //if were inserting in the first position
    if (num == 0) {
        //have head point to new node and new node to point to the original first node
        head = newNode;
        newNode->next = leftNode;
        return num;
    }

    //when theres only one node, itll never enter the while loop
    while (leftNode->next != nullptr) {
        if (num == position) {
            //if target is found, save rightNode as a temp to the right
            rightNode = leftNode->next; //null
            //set leftNode to point to new node
            leftNode->next = newNode;
            //have new node point to the updated right node
            newNode->next = rightNode;
            index++;
            return num;
            break;
        }
        //iterate nodes
        leftNode = leftNode->next;
        rightNode = rightNode->next;
        position++;
        //if the node insert is on the end
        if (leftNode->next == nullptr && num == position) {
            //set the last to point to new node
            leftNode->next = newNode;
            return num;
        }
    }

    //if inserting at the first position and the list is empty
    if (leftNode->next == nullptr && num == position) {
        leftNode->next = newNode;
        return num;
    }

    //if we reach the end and don't find anything
    if (num > position) {
        return -1;
    }

}

int LinkedList::deleteNode(int num) {
    int position = 1;
    if (head == nullptr) {
        return -1;
    }
    //create 2 pointer nodes
    Node *leftNode = head;
    Node *rightNode = head;

    //if deleting first node
    if (num == 0) {
        delete leftNode;
        head = leftNode->next;
        index--;
        return num;
    }


    while (leftNode->next != nullptr) {
        //iterate right node 1 furthur than left node
        if (position == 1) {
            rightNode = rightNode->next;
        } else {
            rightNode = rightNode->next;
            leftNode = leftNode->next;
        }
        //if we are deleting a node on the end:
        if (rightNode->next == nullptr && num == position) {
            delete rightNode;
            leftNode->next = nullptr;
            index--;
            return num;
        }
        //if deleteing a middle node:
        if (num == position) {
            leftNode->next = rightNode->next;
            delete rightNode;
            index--;
            break;
        }
        position++;

    }
    if (num > index) {
        return -1;
    }


}

void LinkedList::display() {
    //if list is empty
    if (head == nullptr) {
        cout << "The list is empty. " << endl;
        return;
    }
    Node *iterator = head;
    int position = 0;
    //iterate through linked list
    while (iterator->next != nullptr) {
        cout << "(" << position << ") " << iterator->data << endl;
        iterator = iterator->next;
        position++;
    }
    cout << "(" << position << ") " << iterator->data << endl;
}

void LinkedList::searchList(string str) {
    if (head == nullptr) {
        cout << "The list is empty, there is nothing to search for. " << endl;
        return;
    }
    Node *iterator = head;
    int position = 0;
    while (iterator->next != nullptr) {
        //if target is found:
        if (iterator->data == str) {
            cout << "There is a " << str << " bead at position (" << position << ") " << endl;
            return;
        }
        //if target isnt found, iterate
        iterator = iterator->next;
        position++;
    }
    //check last node
    if (iterator->data == str) {
        cout << "There is a " << str << " bead at position (" << position << ") " << endl;
        return;
    }
    cout << str << " was not found anywhere. " << endl;

}



