//
// Created by Lumen on 3/21/24.
//

#ifndef CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
#define CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H

#include "Node.cpp"
#include <iostream>

class LinkedList {
private:
    Node *head;
    int index;
public:
    LinkedList();
    ~LinkedList();

    void appendList(string &str);

    int insertList(string &str, int &num);

    int deleteNode(int num);

    void display();

    void searchList(string str);

};


#endif //CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
