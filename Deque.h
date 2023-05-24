#ifndef _DEQUE_H_
#define _DEQUE_H_
#include "Stack.h"
#include <iostream>
using namespace std;

template<typename T>
class Deque: public Stack<T>{
protected:
    Element<T> *frontElement;
public:
    Deque();
    ~Deque();
    T back();
    T front();
    void push_back(T data);
    void push_front(T data);
    void push(T data, int idx);
    T pop_back();
    T pop_front();
    T pop(int idx);
    void print();
};

template<typename T>
Deque<T>::Deque()
    :Stack<T>::Stack(), frontElement{nullptr}{
}
template<typename T>
Deque<T>::~Deque(){
    while(Deque<T>::capacityStack != 0)
        Deque<T>::pop_back();
}
template<typename T>
T Deque<T>::back(){
    return Stack<T>::top();
}
template<typename T>
T Deque<T>::front(){
    return frontElement->data;
}
template<typename T>
void Deque<T>::push_back(T node){
    Stack<T>::push(node);
    if(Deque<T>::capacityStack ==1)
        frontElement = Deque<T>::topElement;
}
template<typename T>
void Deque<T>::push_front(T pdata){
    if(frontElement == nullptr){
        frontElement = new Element<T>{pdata, nullptr};
        Deque<T>::topElement = frontElement;
    }
    else{
        Element<T>* tmp = new Element<T>{pdata, nullptr};
        frontElement->next = tmp;
        frontElement = frontElement->next;
    }
    Deque<T>::capacityStack += 1;
}
template<typename T>
void Deque<T>::push(T pdata, int idx){
    if(idx==0)
        push_back(pdata);
    else if(idx == Deque<T>::capacityStack)
        push_front(pdata);
    else if(idx > Deque<T>::capacityStack || idx < 0)
        return;
    else{
        Element<T>* tmp = Deque<T>::topElement;
        for(int i=1; i<idx; ++i)
            tmp = tmp->next;
        tmp->next = new Element<T>{pdata, tmp->next};
        Deque<T>::capacityStack += 1;
    }
}
template<typename T>
T Deque<T>::pop_back(){
    return Stack<T>::pop();
}
template<typename T>
T Deque<T>::pop_front(){
    T returnData = frontElement->data;
    Element<T>* tmp = Deque<T>::topElement;
    while(tmp->next != frontElement)
        tmp = tmp->next;
    frontElement = tmp;
    tmp = tmp->next;
    frontElement->next=nullptr;
    delete tmp;
    Deque<T>::capacityStack -= 1;
    return returnData;
}
template<typename T>
T Deque<T>::pop(int idx){
    T returnData;
    if(idx == 0)
        returnData = pop_back();
    else if(Deque<T>::capacityStack <= idx || idx < 0){
        return (T)NULL;
    }
    else if(Deque<T>::capacityStack-1 == idx)
        returnData = pop_front();
    else{
        Element<T>* tmp = Deque<T>::topElement;
        for(int i=1; i<idx; ++i)
            tmp = tmp->next;
        Element<T>* toDelete = tmp->next;
        tmp->next = toDelete->next;
        returnData = toDelete->data;
        delete toDelete;
    }
    Deque<T>::capacityStack -= 1;
    return returnData;
}
template<typename T>
void Deque<T>::print(){
    Element<T>* tmp = Deque<T>::topElement;
    while(tmp->next != nullptr){
        cout<<tmp->data<<" -> ";
        tmp = tmp->next;
    }
    cout<<tmp->data<<endl;;
}
#endif // _DEQUE_H_