#include<iostream>
using namespace std;

class A
{
    public:
        A()
        {
            cout<<"Class A"<<endl;
        }
};

class B: public A
{
    public:
        B()
        {
            cout<<"Class B"<<endl;
        }
};

class C: public B
{
    public:
        C()
        {
            cout<<"Class C"<<endl;
        }
};

int main()
{
    C c;
    return 0;
}