//
// Created by Kareem Nabulsi on 3/21/24.
//

#ifndef CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
#define CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
#include "Node.cpp"

class LinkedList {
private:
    Node* head;
    Node* tail;
    int index;
public:
    LinkedList();
    void appendList(string& str);
    void insertList(string& str, int& num);
    void deleteList(Node*node);
    void display(Node*node);
    void searchList(Node*node);

};


#endif //CHAPTER19PROGRAMMINGASSIGNMENT_LINKEDLIST_H
