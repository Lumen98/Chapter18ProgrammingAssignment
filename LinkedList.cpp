//
// Created by Kareem Nabulsi on 3/21/24.
//

#include "LinkedList.h"
#include "Node.cpp"
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
    Node* newNode = new Node(str);
    Node* tempNode = head;
    while(tempNode->next != nullptr) {
        if(num == index) {
            tempNode->next = newNode;
            break;
        }
        tempNode = tempNode->next;
        index++;
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



