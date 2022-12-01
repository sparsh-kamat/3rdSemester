#include<iostream>
using namespace std;

class A
{   
    public:
        int a;
        int b;
        void get_a(int x)
        {
            a = x;
        }
        void show_a()
        {
            cout << "Value of a is " << a << endl;
        }
        void display()
        {
            cout<<"Class A"<<endl;
        }

        void get_b(int y)
        {
            b = y;
        }
        void show_b()
        {
            cout << "Value of b is " << b << endl;
        }
};

class B: public A
{
    public:
        void show_a()
        {
            cout << "Value of a is " << a << endl;
        }
        void display()
        {
            cout<<"Class B"<<endl;
        }
};


class C: public A
{
    public:
        void display()
        {
            cout<<"Class C"<<endl;
        }
};

int main()
{
    B b;
    C c;
    b.get_a(10);
    b.display();
    b.show_a();
    c.display();
    c.get_b(20);
    c.show_b();
    return 0;
}