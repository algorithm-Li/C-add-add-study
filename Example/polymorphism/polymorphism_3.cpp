/****************************************************
 * File: polymorphism_3.cpp.c
 * Create: 2021/11/24/0024
 * Description:  类指针各种演示
 * Author: Algorithm-Li
****************************************************/

#include<iostream>
using namespace std;

class  Base
{
public:
	Base(char xx) { x = xx; }
	void who() { cout << "Base class: " << x << "\n"; }
protected:
	char x;
};

class  First_d : public  Base
{
public:
	First_d(char xx, char yy) :Base(xx) { y = yy; }
	void who() { cout << "First derived class: " << x << ", " << y << "\n"; }
protected:
	char y;
};

class  Second_d : public  First_d
{
public:
	Second_d(char xx, char yy, char zz) : First_d(xx, yy) { z = zz; }
	void who() { cout << "Second derived class: " << x << ", " << y << ", " << z << "\n"; }
protected:
	char z;
};
int main()
{
	Base  B_obj('A');
	First_d F_obj('T', 'O');
	Second_d S_obj('E', 'N', 'D');
	Base  * p;

	///用基类指针引用一个派生类对象——只能引用派生类中的基类成员。必须通过强制类型转换，才能访问派生类自定义成员
	p = &B_obj;   p->who();//调用是Base的成员函数
	p = &F_obj;   p->who();//调用是Base的成员函数
	p = &S_obj;   p->who();//调用是Base的成员函数

	cout << "===================================="<<endl;

	//子类重定义函数，覆盖了基类的函数，用子类直接调用同名函数时只调用自身的重定义后的函数
	F_obj.who();
	//如若想调用基类的同名函数，则需加域名
	F_obj.Base::who();

    cout << "===================================="<<endl;

	//强制转换
	((First_d*)p)->who();

	((Second_d *)p)->who();

    return 0;
}

//输出
/*
Base class: A
Base class: T
Base class: E
====================================
First derived class: T, O
Base class: T
====================================
First derived class: E, N
Second derived class: E, N, D

*/