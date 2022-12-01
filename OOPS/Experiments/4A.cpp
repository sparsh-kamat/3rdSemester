#include <iostream>
using namespace std;

class change
{
    int a;

public:
    change()
    {
        a = 3;
    }

    void display()
    {
        cout << a << endl;
    }

    change operator++()
    {
        change temp;
        temp.a = ++a;
        return temp;
    }

    change operator++(int)
    {
        change temp;
        temp.a = a++;
        return temp;
    }

    change operator--()
    {
        change temp;
        temp.a = --a;
        return temp;
    }

    change operator--(int)
    {
        change temp;
        temp.a = a--;
        return temp;
    }
};

int main()
{
    change x;
    cout << "x = ";
    x.display();

    cout << "x = x++ = ";
    x = x++;
    x.display();

    cout << "x = ++x = ";
    x = ++x;
    x.display();

    cout << "x = --x = ";
    x = --x;
    x.display();

    cout << "x = x-- = ";
    x = x--;
    x.display();

    return 0;
}
