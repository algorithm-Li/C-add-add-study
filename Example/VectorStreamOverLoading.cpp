/****************************************************
 * File: test_5.cpp.c
 * Create: 2021/11/19/0019
 * Description:
 * Author: Algorithm-Li
****************************************************/

#include<iostream>
#include<cstdlib>
using namespace std;

class vector {
public :
    vector(int size = 1);
    ~vector();
    int &operator[](int i);
    friend ostream &operator<<(ostream &output, vector &);
    friend istream &operator>>(istream &input, vector &);

private :
    int *v;
    int len;
};

vector::vector(int size) {
    if (size <= 0 || size > 100) {
        cout << "The size of " << size << " is null !\n";
        abort();
    }
    v = new int[size];
    len = size;
}

vector::~vector() {
    delete[] v;
    len = 0;
}

int &vector::operator[](int i) {
    if (i >= 0 && i < len) return v[i];
    cout << "The subscript " << i << " is outside !\n";
    abort();
}

ostream &operator<<(ostream &output, vector &ary) {
    for (int i = 0; i < ary.len; i++) output << ary[i] << "  ";
    output << endl;
    return output;
}

istream &operator>>(istream &input, vector &ary) {
    for (int i = 0; i < ary.len; i++) input >> ary[i];
    return input;
}

int main() {
    int k;
    cout << "Input the length of vector A :\n";
    cin >> k;
    vector A(k);
    cout << "Input the elements of vector A :\n";
    cin >> A;
    cout << "Output the elements of vector A :\n";
    cout << A;
}

//输出 output
/*
Input the length of vector A :
6
Input the elements of vector A :
12 35 76 28 91 74
Output the elements of vector A :
12  35  76  28  91  74
*/
