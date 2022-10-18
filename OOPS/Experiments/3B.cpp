//Write a C++ program to understand concept of copy constructors
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
    complex(complex &c)
    {
        a = c.a;
        b = c.b;
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
    complex c2 = c1;  //c2(c1)
    cout<<"c1 --> ";
    c1.showdata();
    cout<<"c2 --> ";
    c2.showdata();
    return 0;
}
