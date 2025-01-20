#include "Stack.h"
#include <iostream>
#include <cstdlib> 

using namespace std;

Stack::Stack(){
    topNode = nullptr;
}


void Stack::push(int value) {
    Node* newNode = new Node(value);
    newNode->next = topNode; 
    topNode = newNode;
}

int Stack::pop() {
    if (isEmpty()) {
        cerr << "Stack underflow: Attempt to pop from an empty stack." << endl;
        exit(EXIT_FAILURE);
    }
    Node* temp = topNode;
    int poppedValue = topNode->data;
    topNode = topNode->next;
    delete temp;
    return poppedValue;
}

int Stack::peek(){
    if (isEmpty()) {
        cerr << "Stack is empty: Cannot peek." << endl;
        exit(EXIT_FAILURE);
    }
    return topNode->data;
}

bool Stack::isEmpty(){
    return (topNode == nullptr);
}
}
