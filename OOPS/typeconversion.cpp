//type conversion
/*
Type conversion
1. Basic to class type
2. Class to basic type
3. Class to class type
*/


#include <iostream>
using namespace std;

class test1
{
private:
    int x;
public:
    test1() { x = 0; }
    test1(int i) { x = i; }
    operator int() { return x; }
    int returnx() { return x; }
    friend test1 operator<<(test1 t, int i);

};

class test2
{   
private:
    int y;
public:
    test2() { y = 0; }
    test2(int i) { y = i; }
    operator test1() { return test1(y); }
    test2(test1 &t) { y = t.returnx(); }
    friend ostream &operator<<(ostream &stream, test2 obj);
};

ostream &operator<<(ostream &stream, test2 obj)
{
    stream << obj.y;
    return stream;
}

test1 operator<<(test1 t, int i)
{
    t.x = i;
    return t;
}

int main()
{
    int a = 10,b;
    test1 t1;
    test2 t2;
    t1 = a;//basic to class type
    cout << t1 << endl;
    b = t1;//class to basic type
    cout << b << endl;
    t2 = t1;//class to class type
    cout << t2 << endl;
    return 0;

}


