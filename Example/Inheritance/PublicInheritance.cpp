/****************************************************
 * File: PublicInheritance.cpp.c
 * Create: 2021/11/20/0020
 * Description: 公有继承
 * Author: Algorithm-Li
****************************************************/

#include<iostream>
using namespace std;

class A {
public :
    void get_XY() {
        cout << "Enter two numbers of x, y : ";
        cin >> x >> y;
    }
    void put_XY()  { cout << "x = " << x << ", y = " << y << '\n'; }
protected:
    int x, y;
};

class B : public A {//公有继承
public :
    int get_S() { return s; };
    void make_S() { s = x * y; }; // 使用基类数据成员x，y
protected:
    int s;
};

class C : public B {//公有继承
public :
    void get_H() {
        cout << "Enter a number of h : ";
        cin >> h;
    }
    int get_V() { return v; }
    void make_V() {
        make_S();
        v = get_S() * h;  // 使用基类成员函数
    }
protected:
    int h, v;
};

int main() {
    A objA;
    B objB;
    C objC;
    //对objA的数据成员操作
    cout << "It is object_A :\n";
    objA.get_XY();
    objA.put_XY();
    cout << "It is object_B :\n";
    objB.get_XY();  //调用基类A成员函数对objB的数据成员操作
    objB.make_S();  //调用派生类B成员函数对objB的数据成员操作
    cout << "S = " << objB.get_S() << endl;
    cout << "It is object_C :\n";
    objC.get_XY();  //调用基类A成员函数对objC的数据成员操作
    objC.get_H();   //调用派生类C成员函数对objC的数据成员操作
    objC.make_V();  //调用派生类C成员函数对objC的数据成员操作
    cout << "V = " << objC.get_V() << endl;

    //错误用法
    //cout<< objB.x;   //错误！在类外不能引用基类的私有成员
    //cout << objB.s;  //错误！在类外不能引用派生类的私有成员

    return 0;
}

/*输入输出：
It is object_A :
Enter two numbers of x, y : 1 2
x = 1, y = 2
It is object_B :
Enter two numbers of x, y : 3 4
S = 12
It is object_C :
Enter two numbers of x, y : 5 6
Enter a number of h : 7
V = 210
 */
