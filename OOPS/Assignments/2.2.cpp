#include <iostream>
using namespace std;

class electricity
{
    char name[20];
    int units;
    float charge;
    public:
    void getdata()
    {
        cout<<"Enter name of user: ";
        cin>>name;
        cout<<"Enter units consumed: ";
        cin>>units;
    }
    void calculate()
    {
        if(units<=100)
        {
            charge=units*0.6;
        }
        else if(units<=300)
        {
            charge=100*0.6+(units-100)*0.8;
        }
        else
        {
            charge=100*0.6+200*0.8+(units-300)*0.9;
        }
        if(charge<50)
        {
            charge=50;
        }
        else if(charge>300)
        {
            charge=charge*1.15;
        }
    }
    void display()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Units consumed: "<<units<<endl;
        cout<<"Charge: "<<charge<<endl<<endl;
    }
};  

int main()
{
    int n;
    cout<<"Enter number of users: ";
    cin>>n;
    electricity *e=new electricity[n];
    for(int i=0;i<n;i++)
    {
        e[i].getdata();
        e[i].calculate();
        e[i].display();
    }
    return 0;

}