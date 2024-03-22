//
// Created by Kareem Nabulsi on 3/21/24.
//

#ifndef CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
#define CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
#include "Node.cpp"

class LinkedList {
private:
    Node* head;
public:
    LinkedList();
    void appendList(Node*node);
    void insertList(Node*node);
    void deleteList(Node*node);
    void display(Node*node);
    void searchList(Node*node);

};


#endif //CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
