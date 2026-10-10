#include "stack.h"
#include <cstring>
#include<iostream>

void stack::izm(int newrazm)
{
    int* newdata = new int[newrazm];
    for(int i=0; i<=index; i++)
    {
        newdata[i]=data[i];
    }
    delete[]data;
    data = newdata;
    razm = newrazm;
}

stack::stack(): razm(10),index(-1){
    data = new int[razm];
}

stack::stack(int kol): razm(kol), index(-1){
    data = new int [razm];
}

stack::stack(const stack&drugoi): razm(drugoi.razm), index(drugoi.index){
    data = new int[razm];
    for(int i=0; i<=index; i++)
    {
        data[i]=drugoi.data[i];
    }
}

stack::~stack(){
    delete[] data;
}

stack& stack::operator=(const stack &drugoi){
    if(this==&drugoi) return*this;
    delete [] data;
    razm=drugoi.razm;
    index=drugoi.index;
    data = new int[razm];
    for(int i=0; i<=index; i++)
    {
        data[i]=drugoi.data[i];
    }
    return *this;
}

stack stack::operator+(const stack &drugoi)const{
    stack result(this->razm+drugoi.razm);
    for(int i=0;i<=this->index;i++){
        result << this->data[i];
    }
    for(int i=0;i<=drugoi.index;i++){
        result << drugoi.data[i];
    }
    return result;
}

std::ostream& operator << (std::ostream& os, const stack& s){
    for(int i=s.index;i>=0;i--){
        os << s.data[i];
    }
    return os;
}

std::istream& operator >> (std::istream& is, stack& s){
    int val;
    if (is >> val)
    {
        s<<val;
    }
    return is;
}

stack& stack::operator<<(int n){
    if(index == razm -1)
    {
        int newrazm = (razm == 0) ? 1: razm *2;
        int * newdata = new int[newrazm];
    for (int i=0; i<= index;i++)
    {
        newdata[i]=data[i];
    }
    delete[] data;
    data = newdata;
    razm = newrazm;
    }
    data[++index]=n;
    return *this;
}

int stack::operator>>(int &n){
    if(index<0){
        throw std::runtime_error("empty");
    }
    n = data[index--];
    return n;
}

stack& stack::operator+=(const stack& drugoi) {
    for (int i = 0; i <= drugoi.index; ++i) {
        *this << drugoi.data[i]; 
    }
    return *this;
}


bool stack::operator==(const stack& drugoi) const {
    if (index != drugoi.index) return false;
    for (int i = 0; i <= index; ++i) {
        if (data[i] != drugoi.data[i]) return false;
    }
    return true;
}

bool stack::operator!=(const stack& drugoi) const {
    return !(*this == drugoi);
}

bool stack::operator<(const stack& drugoi) const {
    int min = (index < drugoi.index) ? index : drugoi.index;
    for (int i = 0; i <= min; ++i) {
        if (data[i] < drugoi.data[i]) return true;
        if (data[i] > drugoi.data[i]) return false;
    }
    return index < drugoi.index;
}

bool stack::operator<=(const stack& drugoi) const { 
    return (*this < drugoi) || (*this == drugoi); 
}
bool stack::operator>(const stack& drugoi) const { 
    return !(*this <= drugoi); 
}
bool stack::operator>=(const stack& drugoi) const { 
    return !(*this < drugoi); 
}


























