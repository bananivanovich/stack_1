#include<iostream>
#include"stack.h"
int main ()
{
    stack s;

    std::cout << "vvedite 3 chisla: ";
    std::cin >> s >> s >> s;

    stack s2;
    s2 << 7 << 8;
    stack s3= s+ s2;
    std::cout << "сумма " << s3 << std::endl;

    int val;
    s3 >> val;
    std::cout << "Извлечен элемент: " << val << std::endl;
    std::cout << "Стек s3 после извлечения: " << s3 << std::endl;

    std::cout << "stack: " << s3 << std::endl;
    return 0;
}
