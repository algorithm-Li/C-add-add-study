/****************************************************
 * File: polymorphism_1.cpp
 * Create: 2021/11/24/0024
 * Description:  基类指针指向派生类类型
 * Author: Algorithm-Li
****************************************************/

//用基类指针引用一个派生类对象——只能引用派生类中的基类成员。必须通过强制类型转换，才能访问派生类自定义成员；
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class  A_class
{
	char name[20];
public:
	void  put_name(char * s) { strcpy_s(name, s); }
	void  show_name() { cout << name << "\n"; }
};
class  B_class : public  A_class
{
	char phone_num[20];
public:
	void  put_phone(char * num) { strcpy_s(phone_num, num); }

	void  show_phone() { cout << phone_num << "\n"; }
};
int main()
{
	A_class  * A_p;
	A_class  A_obj = A_class();
	B_class  B_obj = B_class();
	A_p = &A_obj;
	A_p->put_name((char*)"Wang xiao hua");
	A_p->show_name();
	A_p = &B_obj;
	A_p->put_name((char*)"Chen ming");
	A_p->show_name();
	B_obj.put_phone((char*)"5555_12345678");
	((B_class *)A_p)->show_phone();
	///A_p->show_phone();  //此处加此行代码无法运行，强制转换只对单行代码有用

	return 0;
}

//输出：
/*
Wang xiao hua
Chen ming
5555_12345678
 */
