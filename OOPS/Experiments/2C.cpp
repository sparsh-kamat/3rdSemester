//Write a C++ program to understand concept of function overloading
#include <iostream>
using namespace std;

void volume(int a)
{
    cout << "Volume of cube is: " << a * a * a << endl;
}

void volume(int l, int b, int h)
{
    cout << "Volume of cuboid is: " << l * b * h << endl;
}

void volume(float r)
{
    cout << "Volume of sphere is: " << (4 / 3) * 3.14 * r * r * r << endl;
}

int main()
{
    int a, l, b, h;
    float r;
    cout << "Enter the side of the cube: " << endl;
    cin >> a;
    volume(a);
    cout << "Enter the length, breadth and height of the cuboid: " << endl;
    cin >> l >> b >> h;
    volume(l, b, h);
    cout << "Enter the radius of the sphere: " << endl;
    cin >> r;
    volume(r);
    return 0;
}

