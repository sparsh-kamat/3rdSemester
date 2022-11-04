#include <iostream>
using namespace std;

//left hand side operand of sny binary operator is by default passed as a reference
//if we want to pass the right hand side operand as a reference we need to use & operator
//if we want to pass the right hand side operand as a pointer we need to use * operator


class test
{
    int a;

public:
    test(int x)
    {
        a = x;
    }
    test()
    {
        a = 0;
    }
    void display()
    {
        cout << a << endl;
    }
    // friend int operator +(test &t1, test &t2);

    int operator +(test &t2)
    {
        return a + t2.a;
    }

};

// int operator +(test &t1, test &t2)
// {
//     return t1.a + t2.a;
// }

int main()
{
    test t1(10), t2(20),t3;
    t3 = t1 + t2;
    
}

