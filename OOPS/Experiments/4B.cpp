#include<iostream>
using namespace std;

class item
{
    int a;
    public:
        void getdata()
        {
            cin >> a;
        }
        friend item operator +(int p, item y)
        {
            item temp;
            temp.a = p + y.a;
            return temp;
        }
        item operator *(item y)
        {
            item temp;
            temp.a = a * y.a;
            return temp;
        }
        friend item operator -(item y,int p)
        {
            item temp;
            temp.a = y.a - p;
            return temp;
        }
        void display()
        {
            cout << a << endl;
        }
};

int main()
{
    item x, y;
    cout<<"Enter the value of y: ";
    y.getdata();

    cout<<"x = 5 + y = ";
    x = 5 + y;
    x.display();

    cout<<"x = x * y = ";
    x = x*y;
    x.display();

    cout<<"x = y - 5 = ";
    x = y - 5;
    x.display();
    return 0;
}

