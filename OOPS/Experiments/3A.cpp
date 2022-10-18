//Write a C++ program to understand concept of parameterized constructors
#include <iostream>
using namespace std;

class complex
{
    int a, b;
    public:
    complex()
    {
        a=0;b=0;
    }
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    void showdata()
    {
        cout << "a = " << a ;
        cout << " b = " << b << endl;
    }
};

int main()
{
    complex c1(3, 4),c2;
    cout<<"c1 --> ";
    c1.showdata();
    return 0;
}

