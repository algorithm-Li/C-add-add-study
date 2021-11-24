/****************************************************
 * File: polymorphism_7.cpp.c
 * Create: 2021/11/24/0024
 * Description: 虚析构函数
 * Author: Algorithm-Li
****************************************************/

//虚析构函数在删除动态派生类对象的调用情况
//定义了基类虚析构函数，基类指针指向的派生类动态对象也可以正确地用delete析构
//设计类层次结构时，提供一个虚析构函数，能够使派生类对象在不同状态下正确调用析构函数
#include<iostream>
using namespace std;
class A
{
public:
	virtual  ~A() { cout << "A::~A() is called.\n"; }
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
	delete Ap;
	cout << "delete second object:\n";
	delete Bp2;
	return 0;
}

//输出：
/*
delete first object:
B::~B() is called.
A::~A() is called.
delete second object:
B::~B() is called.
A::~A() is called.
 */