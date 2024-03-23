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
        index++;
    }
    tempNode->next = newNode;
    tail = newNode;
    cout << "Thank you - a " << str << " bead has been added to your necklace at position " << index << "." << endl;
}

void LinkedList::insertList(string& str, int& num) {
    try {
        if(head == nullptr) {
            throw runtime_error("");
        }
        Node* newNode = new Node(str);
        Node* leftNode = head;
        Node* rightNode = head;
        while(leftNode->next != nullptr) {
            if(num == index) {
                rightNode = leftNode->next;
                leftNode->next = newNode;
                newNode->next = rightNode;
                break;
            }
            leftNode = leftNode->next;
            rightNode = rightNode->next;
            index++;
        }
        if(num > index) {
            throw runtime_error("");
        }
        cout << "Thank you - a " << str << " bead has been inserted at position " << index  << "." << endl;
    }
    catch(const runtime_error& e) {
        cout << "I’m sorry but bead position " << num << " does not exist." << endl;
    }

}

void LinkedList::deleteList(Node*node) {

}

void LinkedList::display(Node*node) {

    while(node != NULL) {
        cout << node->data << endl;
        node = node->next;
    }

}

void LinkedList::searchList(Node*node) {

}



