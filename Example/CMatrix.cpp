/****************************************************
 * File: CMatrix.cpp
 * Create: 2021/11/19/0019
 * Description:
 * Author: Algorithm-Li
****************************************************/

#include <iostream>
using namespace std;

class CMatrix {
public:
    CMatrix(int x = 3, int y = 3);
    CMatrix(const CMatrix& a);
    ~CMatrix();
    friend istream &operator>>(istream &input, CMatrix &m);
    friend ostream &operator<<(ostream &output,CMatrix &m);
    friend CMatrix operator+(const CMatrix &m1, const CMatrix &m2);
    CMatrix& operator=(const CMatrix &cls);
protected:
    int mx, my;
    int **pm;
};

CMatrix::CMatrix(int x, int y) {
    cout << "调用默认参数构造函数！"<<endl;
    mx = x;
    my = y;
    pm = new int *[mx];
    for (int i1 = 0; i1 < mx; i1++) {
        pm[i1] = new int[my];
    }
}

//复制构造函数
CMatrix::CMatrix(const CMatrix &a) {
    cout << "调用复制构造函数"<<endl;
    this->mx = a.mx;
    this->my = a.my;
    this->pm = new int *[mx];
    for (int i1 = 0; i1 < mx; i1++) {
        pm[i1] = new int[my];
        for (int i2 = 0; i2 < my; i2++)
            this->pm[i1][i2] = a.pm[i1][i2];
    }
}

CMatrix::~CMatrix() {
    for (int i1 = 0; i1 < mx; i1++)
        delete[] pm[i1];
    delete[]pm;
}

CMatrix& CMatrix::operator=(const CMatrix &cls) {
    cout << "调用赋值运算符重载函数！" << endl;
    //避免自赋值
    if(this != &cls){
        //避免内存泄露
        if(pm != nullptr){
            for (int i1 = 0; i1 < mx; i1++)
                delete[] pm[i1];
            delete[]pm;
        }
        //赋值
        this->mx = cls.mx;
        this->my = cls.my;
        this->pm = new int *[mx];
        for (int i1 = 0; i1 < mx; i1++) {
            pm[i1] = new int[my];
            for (int i2 = 0; i2 < my; i2++)
                this->pm[i1][i2] = cls.pm[i1][i2];
        }
    }
    return *this;
}

istream &operator>>(istream &input, CMatrix &m) {
    cout << "调用流提取运算符重载函数！" << endl;
    for (int i1 = 0; i1 < m.mx; i1++)
        for (int i2 = 0; i2 < m.my; i2++)
            input >> m.pm[i1][i2];
    return input;
}

CMatrix operator+(const CMatrix &m1, const CMatrix &m2) {
    cout << "调用加法运算符重载函数"<<endl;
    CMatrix back(m1.mx,m1.my);
    if(m1.mx == m2.mx && m1.my == m2.my){
        for (int i1 = 0; i1 < m1.mx; i1++) {
            for (int i2 = 0; i2 < m1.my; i2++) {
                back.pm[i1][i2] = m1.pm[i1][i2] + m2.pm[i1][i2];
            }
        }
        return back;
    }else{
        cout <<"the dimension is not the same!"<<endl;
        return CMatrix();
    }
}

ostream &operator<<(ostream &output, CMatrix &m) {
    cout << "调用流插入运算符重载函数！" << endl;
    for (int i1 = 0; i1 < m.mx; i1++) {
        for (int i2 = 0; i2 < m.my; i2++) {
            cout << m.pm[i1][i2] <<"\t";
        }
        cout << endl;
    }
    return output;
}

int main(){
    cout<<"请输入a矩阵"<<endl;
    CMatrix a(2,3);
    cin >> a;
    cout<<"请输入b矩阵"<<endl;
    CMatrix b(2,3);
    cin >> b;
    cout << "========="<<endl;
    CMatrix c;
    c = a+b;
    cout << c;
    return 0;
}

/*输入输出内容
 * 
请输入a矩阵
调用默认参数构造函数！
调用流提取运算符重载函数！
1 2 3
4 5 6
请输入b矩阵
调用默认参数构造函数！
调用流提取运算符重载函数！
1 2 3
4 5 6
=========
调用默认参数构造函数！
调用加法运算符重载函数
调用默认参数构造函数！
调用复制构造函数
调用赋值运算符重载函数！
调用流插入运算符重载函数！
2	4	6	
8	10	12	
 *
 */
