/****************************************************
 * File: PrivateInheritance_2.cpp.c
 * Create: 2021/11/20/0020
 * Description: 私有数据成员继承测试
 * Author: Algorithm-Li
****************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() { x = 1; }
    int out() { return x; }
    void addX() { x++; }
private:
    int x;
};

class B : public A {
public:
    B() { y = 1; }
    int out() { return y; }
    void addY() { y++; }
private:
    int y;
    //基类的私有数据成员
    //不能在派生类中直接访问
    //但派生类对象建立私有数据空间 int x
};

int main() {
    A a;    //调用构造函数对数据成员赋值
    B b;    //创建派生类对象调用基类  派生类构造函数 b.x = 1 b.y = 1
    b.addX();  //调用基类公有成员函数  b.x++
    b.addY();  //调用派生类公有成员函数  b.y++
    cout << "a.x=" << a.out() << endl;
    cout << "b.x=" << b.A::out() << endl;   // b.A::out()调用基类版本同名函数返回 b.x 的值
    cout << "b.y=" << b.out() << endl;     // b.out调用派生类版本同名函数返回 b.y 的值
    return 0;
}

/*输入输出
a.x=1
b.x=2
b.y=2
 */
