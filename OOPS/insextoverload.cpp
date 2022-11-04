//overload >> and << operators

#include <iostream>
using namespace std;

class insextoverload
{
private:
    int x;
public:
    insextoverload(int i) { x = i; }
    int getx() { return x; }
    friend ostream &operator<<(ostream &stream, insextoverload obj);
    friend istream &operator>>(istream &stream, insextoverload &obj);
};

ostream &operator<<(ostream &stream, insextoverload obj)
{
    stream << obj.x;
    return stream;
}

istream &operator>>(istream &stream, insextoverload &obj)
{
    stream >> obj.x;
    return stream;
}


int main()
{
    insextoverload obj(10);
    cout << obj << endl;
    cin >> obj;
    cout << obj << endl;
    return 0;
}

