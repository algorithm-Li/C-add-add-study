/****************************************************
 * File: PrivateInheritance_1.cpp
 * Create: 2021/11/20/0020
 * Description: 私有继承的测试
 * Author: Algorithm-Li
****************************************************/

#include <iostream>
using namespace std;

class A {
public :
    void get_XY() {
        cout << "Enter two numbers of x and y : ";
        cin >> x >> y;
    }
    void put_XY() {
        cout << "x = " << x << ", y = " << y << '\n';
    }

protected:
    int x, y;
};

class B : private A {
public :
    int get_S() { return s; }

    void make_S() {
        get_XY(); //调用基类成员函数
        s = x * y; //访问私有数据成员
    }

private:
    int s;
};

int main() {
    B objB;
    cout << "It is object_B :\n";
    objB.make_S();
    cout << "S = " << objB.get_S() << endl;

    //错误写法
    //objB.put_XY();  //错误，私有基类的公用成员函数在派生类中是私有函数
    return 0;
}

/*输入输出
It is object_B :
Enter two numbers of x and y : 10 20
S = 200
 */
