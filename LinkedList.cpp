//
// Created by Kareem Nabulsi on 3/21/24.
//

#include "LinkedList.h"
#include "Node.cpp"
#include <iostream>
using namespace std;

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::appendList(Node*node) {


}

void LinkedList::insertList(Node*node) {

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



