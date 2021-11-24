/****************************************************
 * File: polymorphism_6.cpp.c
 * Create: 2021/11/24/0024
 * Description: 析构函数
 * Author: Algorithm-Li
****************************************************/

//构造函数不能是虚函数。建立一个派生类对象时，必须从类层次的根开始，沿着继承路径逐个调用基类的构造函数
//析构函数可以是虚的。虚析构函数用于指引 delete 运算符正确析构动态对象
#include<iostream>
using namespace std;
class A
{
public:
	~A() { cout << "A::~A() is called.\n"; }
};
class B : public A
{
public:
	~B() { cout << "B::~B() is called.\n"; }
};
int main()
{
	A *Ap = new B;
	B *Bp2 = new B;
	cout << "delete first object:\n";
	delete Ap;          //指向派生类的基类指针不能正确调用析构函数，派生类对象没有被析构
	cout << "delete second object:\n";
	delete Bp2;			//析构由派生类指针建立的派生类对象正确调用派生类析构函数
	return 0;
}

//输出
/*
delete first object:
A::~A() is called.
delete second object:
B::~B() is called.
A::~A() is called.
 */