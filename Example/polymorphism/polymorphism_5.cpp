/****************************************************
 * File: polymorphism_5.cpp.c
 * Create: 2021/11/24/0024
 * Description:
 * Author: Algorithm-Li
****************************************************/

//在派生类中重载基类的虚函数要求函数名、返回类型、参数个数、参数类型和顺序完全相同------重点、、注意*****
//如果仅仅返回类型不同，C++认为是错误重载
//如果函数原型不同，仅函数名相同，丢失虚特性，只是一般的函数重载
class  base
{
public:
	virtual  void  vf1();
	virtual  void  vf2();
	virtual  void  vf3();
	void  f();
};

class  derived : public  base
{
public:
	void  vf1();	// 虚函数
	void  vf2(int);	// 参数不同，虚特性丢失。只是一般函数重载
	char  vf3();	// error，仅返回类型不同
	void f();		// 非虚函数重载
};
