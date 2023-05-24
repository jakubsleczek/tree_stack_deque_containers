#include "Tree.h"


Tree::Tree(string pdata)
    :data{pdata}, nextSib{nullptr}, firstChild{nullptr}{

}

Tree::~Tree(){
    if(firstChild != nullptr){
        delete firstChild;
    }
    if(nextSib != nullptr){
        delete nextSib;
    }
}

Tree* Tree::AddSub(string pdata){
    Tree* current = firstChild;
    if(current == nullptr){
        firstChild = new Tree(pdata);
        return firstChild;
    }
    else{
        while(current->nextSib != nullptr)
            current = current->nextSib;
        current->nextSib = new Tree(pdata);
        return current->nextSib;
    }
}

void Tree::print(int i){
    for(int j=0 ; j<i; j++)
        cout<<" ";
    cout<<data<<endl;
    if(firstChild != nullptr){
        ++i;
        firstChild->print(i);
        --i;
    }
    if(nextSib != nullptr)
        nextSib->print(i);
}

void Tree::print(int i, bool state, ...){
    if(state){
        va_list lista;
        va_start(lista, state);
        int* header = va_arg(lista,int*);
        int* temp = header;
        va_end(lista);
        for(int j=0 ; j<i; j++)
            cout<<" ";
        for(int j=0 ; j<i; j++){
            cout<<*temp<<".";
            temp++;
        }
        if(i!=0)
            cout<<" ";
        cout<<data<<endl;
            if(firstChild != nullptr){
                int* va_table = header;
                ++i;
                int table[i];
                for(int j=0; j<i-1; ++j){
                    table[j]=*va_table;
                    va_table++;
                }
                table[i-1]=1;
                firstChild->print(i, state, table);
                --i;
            }
            if(nextSib != nullptr){
                int* va_table = header;
                int table[i];
                for(int j=0; j<i; ++j){
                    table[j]=*va_table;
                    va_table++;
                }
                table[i-1]=table[i-1]+1;
                nextSib->print(i, state, table);
            }
    }
    else
        print(i);
}

int Tree::GetSubCount(){
    int result{0};
    Tree* current = firstChild;
    while(current != nullptr){
        result++;
        current = current->nextSib;
    }
    return result;
}

int Tree::GetAllSubCount(){
    int result{0};
    helper(result);
    return result;
}

int Tree::helper(int &result){
    if(firstChild != nullptr){
        firstChild->helper(result);
        result++;
    }
    if(nextSib != nullptr){
        nextSib->helper(result);
        result++;
    }
    return result;
}
void Tree::Del(int index){
    Tree* current = nullptr;
    Tree* previous = nullptr;
    if(index == 0){
        current = firstChild;
        firstChild = firstChild->nextSib;
    }
    else{
        previous = firstChild;
        current = firstChild->nextSib;
        for(int i=1; i<index; ++i){
            current = current->nextSib;
            previous = previous->nextSib;
        }
        previous->nextSib = current->nextSib;
    }
        current->nextSib = nullptr;
        delete current;
}

void Tree::toFile(){
    ofstream file;
    file.open("zapis.txt");
    if(!file){
        cout<<"Error: cannot create the file\n";
        return;
        }
    toFileHelper(0, file);
    file.close();
}

void Tree::toFileHelper(int i, ofstream &file){
    for(int j=0 ; j<i; j++)
        file<<" ";
    file<<data<<endl;
    if(firstChild != nullptr){
        ++i;
        firstChild->toFileHelper(i, file);
        --i;
    }
    if(nextSib != nullptr)
        nextSib->toFileHelper(i, file);
}

void Tree::fromFile(){
    ifstream file;
    int previousLevel{0};
    int currentLevel{0};
    file.open("odczyt.txt");
    if(!file){
        cout<<"Error: cannot open the file\n";
        return;
    }
    getline(file, data);
    fromFileHelper(previousLevel, currentLevel, file, this);
    file.close();
}
string Tree::fromFileHelper(int &previousLevel, int &currentLevel, istream &file, Tree* obj){
    string name;
    currentLevel=0;
    bool levelUp = false;
    getline(file, name);
    for(char c : name){
        if(c == ' '){
            currentLevel += 1;
        }
        else{
            break;
        }
    }
    if(!name.empty() && ((currentLevel-previousLevel) >= 0)){
        if(currentLevel-previousLevel == 1){
            previousLevel = currentLevel;
            obj->firstChild = new Tree(name.substr(currentLevel));
            name = fromFileHelper(previousLevel, currentLevel, file, obj->firstChild);
            levelUp = true;
        }
        if(levelUp)
            previousLevel -= 1;
        if(currentLevel-previousLevel == 0 && !name.empty()){
            previousLevel = currentLevel;
            obj->nextSib = new Tree(name.substr(currentLevel));
            name = fromFileHelper(previousLevel, currentLevel, file, obj->nextSib);
        }
    }
    return name;
}
