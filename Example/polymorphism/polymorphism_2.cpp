/****************************************************
 * File: polymorphism_2.cpp
 * Create: 2021/11/24/0024
 * Description:
 * Author: Algorithm-Li
****************************************************/

//用派生类指针引用一个基类对象——只有经过强制类型转换之后，才能引用基类对象.
#include<iostream>
#include<cstring>
using namespace std;

class Date
{
public:
	Date(int y, int m, int d) { SetDate(y, m, d); }
	void SetDate(int y, int m, int d) { year = y; month = m; day = d; }
	void Print() { cout << year << '/' << month << '/' << day << "; "; }
protected:
	int year;
	int month;
	int day;
};
class DateTime : public Date
{
public:
	DateTime(int y, int m, int d, int h, int mi, int s) : Date(y, m, d) { SetTime(h, mi, s); }
	void SetTime(int h, int mi, int s) { hours = h;  minutes = mi;  seconds = s; }
	void Print()
	{
		((Date *)this)->Print();				//将this指针强制转化为Date类型，才能调用基类成员
		//Date::Print();						//使用“ :: ”加以区分
		cout << hours << ':' << minutes << ':' << seconds << '\n';
	}
private:
	int hours;
	int minutes;
	int seconds;
};
int main()
{
	DateTime dt(2003, 1, 1, 12, 30, 0);
	dt.Print();
}

//输出
/*
2003/1/1; 12:30:0
 */

