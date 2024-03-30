//
// Created by Kareem Nabulsi on 3/21/24.
//

#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
    tail = nullptr;
    index = 0;
}

void LinkedList::appendList(string& str) {
    Node* newNode = new Node(str);
    if(head == nullptr) {
        head = newNode;
        cout << "Thank you - a " << str << " bead has been added to your necklace at position " << index << "." << endl;
        return;
    }

    Node* tempNode = head;
    while(tempNode->next != nullptr) {
        tempNode = tempNode->next;
    }
    index++;
    tempNode->next = newNode;
    tail = newNode;
    cout << "Thank you - a " << str << " bead has been added to your necklace at position " << index << "." << endl;
}

int LinkedList::insertList(string& str, int& num) {
    int position = 1;
    try {
        if(head == nullptr) {
            return -1;
            throw runtime_error("");
        }

        Node* newNode = new Node(str);
        Node* leftNode = head;
        Node* rightNode = head;
        if(num == 0) {
            head = newNode;
            newNode->next = leftNode;
            cout << "Thank you - a " << str << " bead has been inserted at position " << num  << "." << endl;
            return num;
        }

        //when theres only one node, itll never enter the while loop
        while(leftNode->next != nullptr) {
            if(num == position) {
                rightNode = leftNode->next; //null
                leftNode->next = newNode;
                newNode->next = rightNode;
                index++;
                break;
            }
            leftNode = leftNode->next;
            rightNode = rightNode->next;
            position++;
            if(leftNode->next == nullptr && num == position) {
                leftNode->next = newNode;
                cout << "Thank you - a " << str << " bead has been inserted at position " << position  << "." << endl;
                return num;
            }
        }

        if(leftNode->next == nullptr && num == position) {
            leftNode->next = newNode;
            cout << "Thank you - a " << str << " bead has been inserted at position " << position  << "." << endl;
            return num;
        }

        if(num > position) {
            return -1;
            throw runtime_error("");
        }
        cout << "Thank you - a " << str << " bead has been inserted at position " << position  << "." << endl;
    }
    catch(const runtime_error& e) {
        cout << "I am sorry but bead position " << num << " does not exist." << endl;
    }

}

int LinkedList::deleteNode(int num) {
    int position = 1;
    try {
        if(head == nullptr) {
            return -1;
            throw runtime_error("");
        }
        Node* leftNode = head;
        Node* rightNode = head;

        if(num == 0) {
            delete leftNode;
            head = leftNode->next;
            cout << "Node (" << num << ") has been deleted from your list. " << endl;
            index--;
            return num;
        }

        while(leftNode->next != nullptr) {
            if(position == 1) {
                rightNode = rightNode->next;
            }
            else {
                rightNode = rightNode->next;
                leftNode = leftNode->next;
            }
            if(rightNode->next == nullptr && num == position) {
                delete rightNode;
                leftNode->next = nullptr;
                cout << "Node (" << num << ") has been deleted from your list. " << endl;
                index--;
                return num;
            }
            if(num == position) {
                leftNode->next = rightNode->next;
                delete rightNode;
                index--;
                break;
            }
            position++;

        }
        if(num > index) {
            return -1;
            throw runtime_error("");
        }
        cout << "Node (" << num << ") has been deleted from your list. " << endl;
    }
    catch(const runtime_error& e) {
        cout << "I’m sorry but node (" << num << ") does not exist." << endl;
    }

}

void LinkedList::display() {
    if(head == nullptr) {
        cout << "The list is empty. " << endl;
        return;
    }
    Node* iterator = head;
    int position = 0;
    while(iterator->next != nullptr) {
        cout << "(" << position << ") " << iterator->data << endl;
        iterator = iterator->next;
        position++;
    }
    cout << "(" << position << ") " << iterator->data << endl;
}

void LinkedList::searchList(string str) {
    if(head == nullptr) {
        cout << "The list is empty, there is nothing to search for. " << endl;
        return;
    }
    Node* iterator = head;
    int position = 0;
    while(iterator->next != nullptr) {
        if(iterator->data == str) {
            cout << "There is a " << str << " bead at position (" << position << ") " << endl;
            return;
        }

        iterator = iterator->next;
        position++;
    }
    if(iterator->data == str) {
        cout << "There is a " << str << " bead at position (" << position << ") " << endl;
        return;
    }
    cout << str << " was not found anywhere. " << endl;

}



