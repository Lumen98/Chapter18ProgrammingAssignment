//
// Created by Kareem Nabulsi on 3/21/24.
//
#include <iostream>
using namespace std;

class Node {
public:
    string data;
    Node* next;

    Node(string str) {
        data = str;
        next = nullptr;
    }
};