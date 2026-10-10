#ifndef STACK_H
#define STACK_H
#include <iostream>
#include <stdexcept>

class stack{
private:
    int *data;
    int razm;
    int index;
    
    void izm(int newrazm);
    
public:
    stack();
        stack(int kol);
        stack(const stack&drugoi);
    
    ~stack();
        stack & operator = (const stack&drugoi);
        stack  operator + (const stack&drugoi)const;
        stack & operator += (const stack&drugoi);
        bool operator == (const stack&drugoi)const;
        bool operator != (const stack&drugoi)const;
        bool operator < (const stack&drugoi)const;
        bool operator <= (const stack&drugoi)const;
        bool operator > (const stack&drugoi)const;
        bool operator >= (const stack&drugoi)const;
        friend std::ostream & operator << (std::ostream& os, const stack& s);
        friend std::istream & operator >> (std::istream& is, stack& s);
        int operator >> (int& n);
        stack & operator << (int n);
};
#endif
