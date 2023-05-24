#ifndef _TREE_H_
#define _TREE_H_
#include <iostream>
#include <stdarg.h>
#include <fstream>
#include <string>
using namespace std;
class Tree{
public:
    string data;
    Tree* nextSib;
    Tree* firstChild;
    Tree(string pdata);
    ~Tree();
    Tree* AddSub(string pdata);
    void print(int i);
    void print(int i, bool state,...);
    int GetSubCount();
    int GetAllSubCount();
    int helper(int &result);
    void Del(int index);
    void toFile();
    void toFileHelper(int i, ofstream &file);
    void fromFile();
    string fromFileHelper(int &previousLevel, int &currentLevel, istream &file, Tree* obj);
    void setData(string pdata){data = pdata;}
};

#endif //_TREE_H_
