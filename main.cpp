#include <iostream>
#include "Tree.h"
#include "Stack.h"
#include "Deque.h"
using namespace std;



int main(){
//**************************TREE************************************
Tree* root = new Tree("tree name");
Tree* galaz1 = root->AddSub("galaz 1");
Tree* galaz2 = root->AddSub("galaz 2");
Tree* galaz3 = root->AddSub("galaz 3");
Tree* galaz1_1 = galaz1->AddSub("galaz 1.1");
Tree* galaz2_1 = galaz2->AddSub("galaz 2.1");
Tree* galaz2_2 = galaz2->AddSub("galaz 2.2");
Tree* galaz2_1_2 = galaz2_1->AddSub("galaz 2.1.2");
cout<<"***************************"<<endl;
root->print(0,true);
cout<<root->GetSubCount()<<endl;
cout<<root->GetAllSubCount()<<endl;
root->toFile();
//delete root;
root->Del(1);
//root->print(0,true,1);
cout<<root->GetSubCount()<<endl;
cout<<root->GetAllSubCount()<<endl;
delete root;
//*******************************************************************
Tree* root1 = new Tree("cos");
root1->fromFile();
root1->print(0,true);
//***********************************STACK*************************************************
Stack<char> *stos = new Stack<char>();
cout<<boolalpha;
cout<<"czy stos jest pusty? "<<stos->isEmpty()<<endl;
stos->push('a');
stos->push('b');
stos->push('c');
stos->push('d');
cout<<"ilosc elementow: "<<stos->capacity()<<"\nzajmowana pamiec: "<<stos->size()<<" bajtow\n";
cout<<"na gorze jest: "<<stos->top()<<endl;
cout<<"czy stos jest pusty? "<<stos->isEmpty()<<endl;
stos->print();
stos->pop();
stos->pop();
cout<<"ilosc elementow: "<<stos->capacity()<<"\nzajmowana pamiec: "<<stos->size()<<" bajtow\n";
cout<<"na gorze jest: "<<stos->top()<<endl;
cout<<"czy stos jest pusty? "<<stos->isEmpty()<<endl;
stos->print();
delete stos;
//**********************************DEQUE**************************************************
Deque<int> *kolejka = new Deque<int>();
cout<<"czy kolejka jest pusty? "<<kolejka->isEmpty()<<endl;
kolejka->push_front(2);
kolejka->push_front(1);
kolejka->push_back(3);
kolejka->push(4,1);
cout<<"ilosc elementow: "<<kolejka->capacity()<<"\nzajmowana pamiec: "<<kolejka->size()<<" bajtow\n";
cout<<"z tylu jest jest: "<<kolejka->back()<<endl;
cout<<"z przodu jest jest: "<<kolejka->front()<<endl;
cout<<"czy kolejka jest pusty? "<<kolejka->isEmpty()<<endl;
kolejka->print();
kolejka->pop(2);
kolejka->pop_back();
cout<<"ilosc elementow: "<<kolejka->capacity()<<"\nzajmowana pamiec: "<<kolejka->size()<<" bajtow\n";
cout<<"z tylu jest jest: "<<kolejka->back()<<endl;
cout<<"z przodu jest jest: "<<kolejka->front()<<endl;
cout<<"czy kolejka jest pusty? "<<kolejka->isEmpty()<<endl;
kolejka->print();
delete kolejka;
return 0;
}
