/*
// write a program to implement a library management system using array of structures with the following operations and
// 1 insert book record`````````````````````````
// 2 & 3 search book record based on title and athor
// 4 display all the book records

// elements will be title,author, number of copies and  subject linked to the book

*/

#include <iostream>
#include <string.h>


using namespace std;

class library
{
public:
    int book_record;
    string title;
    string author;
    int number_of_copies;
    string subject;
    void getdata();
    void display();
};


void library::getdata()
{
    fflush(stdin);
    cout << "\nEnter the title of the book: " << endl;
    cin >> title;
    fflush(stdin);
    cout << "Enter the author of the book: " << endl;
    getline(cin, author);
    fflush(stdin);
    cout << "Enter the subject of the book: " << endl;
    getline(cin, subject);
    fflush(stdin);
    cout << "Enter the number of copies of the book: " << endl;
    cin >> number_of_copies;
    fflush(stdin);
    
}

void library::display()
{
    cout << "\nTitle of the book: " << title << endl;
    cout << "Author of the book: " << author << endl;
    cout << "Number of copies of the book: " << number_of_copies << endl;
    cout << "Subject of the book: " << subject << "\n\n";
}

void searchauthor(library l[], int count)
{
    string author;

    cout << "Enter the author name: " << endl;
    fflush(stdin);
    getline(cin, author);
    for (int i = 0; i < count; i++)
    {
        if (l[i].author == author)
        {
            l[i].display();
        }
    }
}

void searchtitle(library l[], int count)
{
    string a;
    cout << "Enter the title name: " << endl;
    fflush(stdin);
    getline(cin, a);
    for (int i = 0; i < count; i++)
    {
        if (l[i].title == a)
        {
            l[i].display();
        }
    }
}

int main()
{
    library l[10];
    int i=0, n, ch;
    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Enter the book record" << endl;
        cout << "2. Search the book record based on title" << endl;
        cout << "3. Search the book record based on author" << endl;
        cout << "4. Display all the book records" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the details of book " << i + 1 << endl;
            l[i].getdata();
            i++;
            break;
        case 2:
            searchtitle(l, n);
            break;
        case 3:
            searchauthor(l, n);
            break;
        case 4:
            for (int j = 0; j < i; j++)
            {
                l[j].display();
            }
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 5);
    return 0;
}