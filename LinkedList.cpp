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

void LinkedList::insertList(string& str, int& num) {
    int position = 0;
    try {
        if(head == nullptr) {
            throw runtime_error("");
        }

        Node* newNode = new Node(str);
        Node* leftNode = head;
        Node* rightNode = head;
        if(num == 0) {
            head = newNode;
            newNode->next = leftNode;
            cout << "Thank you - a " << str << " bead has been inserted at position " << position  << "." << endl;
            return;
        }
        while(leftNode->next != nullptr) {
            if(num == position) {
                rightNode = leftNode->next; //null
                leftNode->next = newNode;
                newNode->next = rightNode;
                break;
            }
            leftNode = leftNode->next;
            rightNode = rightNode->next;
            position++;
        }
        if(num > position) {
            throw runtime_error("");
        }
        cout << "Thank you - a " << str << " bead has been inserted at position " << position  << "." << endl;
    }
    catch(const runtime_error& e) {
        cout << "I’m sorry but bead position " << num << " does not exist." << endl;
    }

}

void LinkedList::deleteList(int num) {
    try {
        if(head == nullptr) {
            throw runtime_error("");
        }
        Node* leftNode = head;
        Node* rightNode = head;
        while(leftNode->next != nullptr) {




        }
        if(num > index) {
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



