#include <iostream> 
using namespace std; 
class election
{
    int *ballots, n, result[6];

public:
    void input();
    void count();
    void display();
};
void election::input()
{
    bool auto_ = 0;
    cout << "Enter the number of ballot papers : ";
    cin >> n;
    ballots = new int[n];
    srand(time(0));
    for (int count = 0; count < n; count++)
    {
        cout << "Enter ballot " << count + 1 << " = ";
        if (auto_ == true)
        {
            ballots[count] = rand() % 15 - 5;
            cout << ballots[count] << endl;
        }
        else
            cin >> ballots[count];
    }
}
void election::count()
{
    for (int count = 0; count < 6; result[count++] = 0)
        ;
    for (int count = 0; count < n; result[ballots[count] > 0 && ballots[count] < 6 ? ballots[count] - 1 : 5]++, count++)
        ;
}
void election::display()
{
    cout << "\n\n";
    for (int count = 0; count < 5; count++)
        cout << "\tContestant " << count + 1 << " = "<<result[count]<<endl;
        cout<< "\tSpoilt ballots = " << result[5] << endl;
}

int main()
{
    election a;
    a.input();
    a.count();
    a.display();
}