//Write a C++ program to understand concept of Destructors
#include <iostream>
using namespace std;

class complex
{
    int a, b;
    public:
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    ~complex()
    {
        cout << "Destructor called" << endl;
    }
    void showdata()
    {
        cout << "a = " << a ;
        cout << " b = " << b << endl;
    }
};

int main()
{
    complex c1(3, 4);
    {
        complex c2;
        {
            complex c3;
        }
    }
    cout<<"c1 --> ";
    c1.showdata();
    return 0;
}

