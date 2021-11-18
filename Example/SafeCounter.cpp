/****************************************************
 * File: test_3.cpp
 * Create: 2021/11/18/0018
 * Description: 安全计数器
 * Author: Algorithm-Li
****************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

class Calculator {
public:
    Calculator() { value = 0; };

    void operator++(); //自增运算符重载

    void operator--();//自减运算符重载

    unsigned int operator()() const; // 函数调用运算符重载

private:
    unsigned int value;
};

int main() {
    Calculator Counter;
    int i;
    for (i = 0; i < 5; i++) {
        ++Counter;//调用重载版本
        cout << "\n Counter = " << Counter();
    }
    for (i = 0; i <= 5; i++) {
        --Counter;//调用重载版本
        cout << "\n Counter = " << Counter();
    }
}

void Calculator::operator++() {
    if (value < 65535) value++;
    else {
        cout << "\nData overflow !" << endl;
        abort();
    }
}

void Calculator::operator--() {
    if (value > 0) value--;
    else {
        cout << "\n Data overflow !" << endl;
        abort();
    }
}

unsigned int Calculator::operator()() const {
    return value; 
}
