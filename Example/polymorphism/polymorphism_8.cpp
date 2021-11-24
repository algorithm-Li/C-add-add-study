/****************************************************
 * File: polymorphism_8.cpp.c
 * Create: 2021/11/24/0024
 * Description: 纯虚函数
 * Author: Algorithm-Li
****************************************************/

#include <iostream>
using namespace std;
class figure
{
protected:
	double x;
	double y;
public:
	void set_dim(double i, double j = 0) { x = i;  y = j; }
	virtual void show_area() = 0; //纯虚函数
};

class triangle : public figure
{
public:
    //派生类实现纯虚函数
	void show_area()
	{
		cout << "Triangle with high " << x << " and base " << y << " has an area of " << x * 0.5*y << "\n";
	}
};
class square : public figure
{
public:
	void show_area()
	{
		cout << "Square with dimension " << x << "*" << y << " has an area of " << x * y << "\n";
	}
};
class circle : public figure
{
public:
	void show_area()
	{
		cout << "Circle with radius " << x;
		cout << " has an area of " << 3.14*x*x << "\n";
	}
};

int main()
{
	figure *p;				// 声明抽象类指针
	triangle t;
	square s;
	circle c;
	p = &t;
	p->set_dim(10.0, 5.0); 	// triangle::set_dim()
	p->show_area();
	p = &s;
	p->set_dim(10.0, 5.0);	// square::set_dim()
	p->show_area();
	p = &c;
	p->set_dim(9.0);		// circle::set_dim()
	p->show_area();

	return 0;
}

/*输出：
Triangle with high 10 and base 5 has an area of 25
Square with dimension 10*5 has an area of 50
Circle with radius 9 has an area of 254.34
 */

//虚函数和多态性使成员函数根据调用对象的类型产生不同的动作
//多态性特别适合于实现分层结构的软件系统，便于对问题抽象时定义共性，实现时定义区别