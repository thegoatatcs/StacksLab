#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val){
            data = val;
            next = nullptr;
        }
    };

    Node* topNode;

public:
    Stack();
    void push(int value);
    int pop();
    int peek();
    bool isEmpty();
};

#endif
