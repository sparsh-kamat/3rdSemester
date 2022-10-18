//Write a C++ program to understand concept of reference variables in functions.
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 10, y = 20;
    cout << "Before swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    swap(x, y);
    cout << "After swapping: " << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    return 0;
}

