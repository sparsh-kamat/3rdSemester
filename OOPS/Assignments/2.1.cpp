#include <iostream>
using namespace std;

class complex
{
    int a, b;
    public:
    void setdata(int x, int y)
    {
        a = x;
        b = y;
    }
    void showdata()
    {
        cout << "Real = " << a ;
        cout << " Imaginary = " << b << endl;
    }
    friend complex sum(complex, complex);
};

complex sum(complex o1, complex o2)
{
    complex o3;
    o3.setdata((o1.a + o2.a), (o1.b + o2.b));
    return o3;
}

int main()
{
    complex c1, c2, c3;
    c1.setdata(3, 4);
    c2.setdata(5, 6);
    //show c1 c2
    cout<<"c1 --> ";
    c1.showdata();
    cout<<"c2 --> ";
    c2.showdata();
    cout<<"c3 --> ";
    c3 = sum(c1, c2);
    c3.showdata();
    return 0;
}
