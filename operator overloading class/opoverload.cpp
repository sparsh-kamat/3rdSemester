#include <iostream>
using namespace std;

class test
{
    int a, b, c;
public:
    //default constructor
    
    void getdata(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }

    void display()
    {
        cout << a << " " << b << " " << c << endl;
    }
//anytime an operator works with an object of a user defined class we need to use operator oveerloading

//operator funcion as a member function
    // void operator -()
    // {
    //     a = -a;
    //     b = -b;
    //     c = -c;
    // }

//operator function as a friend function
    friend void operator -(test &t);
};


void operator -(test &t)
{
    t.a = -t.a;
    t.b = -t.b;
    t.c = -t.c;
}

int main()
{
    test t1;
    t1.getdata(10, 20,30);
    t1.display();
    -t1;
    t1.display();
    return 0;

}

