#ifndef _STACK_H_
#define _STACK_H_
#include "Element.h"
#include <iostream>
using namespace std;
template<typename T>
class Stack{
protected:
    Element<T> *topElement;
    int capacityStack;
public:
    Stack();
    ~Stack();
    void push(T ptop);
    T pop();
    T top();
    int size();
    int capacity();
    bool isEmpty();
    void print();
};

template<typename T>
Stack<T>::Stack()
    :topElement{nullptr}, capacityStack{0}{
}

template<typename T>
Stack<T>::~Stack(){
    while(capacityStack != 0)
        pop();
}

template<typename T>
void Stack<T>::push(T pdata){
    if(topElement == nullptr)
        topElement = new Element<T>{pdata, nullptr};
    else{
        Element<T>* tmp = topElement;
        topElement = new Element<T>{pdata, tmp};
    }
    capacityStack += 1;
}

template<typename T>
T Stack<T>::pop(){
    T returnData = topElement->data;
    Element<T>* tmp = topElement;
    topElement = topElement->next;
    delete tmp;
    capacityStack -= 1;
    return returnData;
}

template<typename T>
T Stack<T>::top(){
    return topElement->data;
}

template<typename T>
int Stack<T>::capacity(){
    return capacityStack;
}

template<typename T>
int Stack<T>::size(){
    return capacityStack*sizeof(T);
}

template<typename T>
bool Stack<T>::isEmpty(){
    return capacityStack==0 ? true : false;
}

template<typename T>
void Stack<T>::print(){
    Element<T>* tmp = topElement;
    while(tmp != nullptr){
        cout<<tmp->data<<endl;
        tmp = tmp->next;
    }
}

#endif // _STACK_H_
