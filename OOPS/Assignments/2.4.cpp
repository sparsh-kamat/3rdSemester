/*An election is contested by five candidates . 
the candidates are numbered 1 to 5 and the voting 
is done by marking the candidate number on the ballot paper .
Write a program to read the ballots and count the votes cast for each 
candidate using an array varible count in case, a numbr i outside range 1 
the ballot should be considered as a spoilt balot and the program a=should also
count the number of spoilt ballots. The program should also display the
result of the election in the form of a table showing the number of votes
*/

#include <iostream>
using namespace std;

class candidate
{
    int num;
    public:
    void getdata()
    {
        cout << "Enter candidate number: ";
        cin >> num;
    }
    void showdata()
    {
        cout << "Candidate number is " << num << endl;
    }
    friend void count(candidate & c, int);
};

void count(candidate c, int count[])
{
    if (c.num == 1)
    {
        count[0]++;
    }
    else if (c.num == 2)
    {
        count[1]++;
    }
    else if (c.num == 3)
    {
        count[2]++;
    }
    else if (c.num == 4)
    {
        count[3]++;
    }
    else if (c.num == 5)
    {
        count[4]++;
    }
    else
    {
        count[5]++;
    }
}

int main()
{
    int count[6] = {0, 0, 0, 0, 0, 0};
    candidate c;
    int i;
    for (i = 0; i < 10; i++)
    {
        c.getdata();
        count(c, count);
    }
    cout << "Candidate 1 got " << count[0] << " votes." << endl;
    cout << "Candidate 2 got " << count[1] << " votes." << endl;
    cout << "Candidate 3 got " << count[2] << " votes." << endl;
    cout << "Candidate 4 got " << count[3] << " votes." << endl;
    cout << "Candidate 5 got " << count[4] << " votes." << endl;
    cout << "Spoilt ballots are " << count[5] << endl;
    return 0;
}
