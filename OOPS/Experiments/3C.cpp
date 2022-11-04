// Write a C++ program to understand concept of Destructors
#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    complex()
    {
        a = 0;
        b = 0;
    }
    complex(int x, int y)
    {
        a = x;
        b = y;
    }
    ~complex()
    {
        cout << "Destructor called " << endl;
    }
    void showdata()
    {
        cout << "a = " << a;
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
            cout << "c3 --> ";
            c3.showdata();
        }
        cout<<"destroying c3"<<endl;
        cout << "c2 --> ";
        c2.showdata();
    }
    cout<<"destroying c2"<<endl;
    cout << "c1 --> ";
    c1.showdata();
    return 0;
}
