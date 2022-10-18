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
    string title;
    string author;
    int book_record;
    int number_of_copies;
    string subject;

public:
    void getdata();
    void display();
    void searchtitle(library l[], int n);
    void searchauthor(library l[], int n);
};

void library::getdata()
{
    fflush(stdin);
    cout << "\nEnter the title of the book: " << endl;
    getline(cin, title);
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

void library::searchtitle(library l[], int n)
{
    string t;
    int flag = 0;
    cout << "Enter the title of the book you want to search: " << endl;
    fflush(stdin);
    getline(cin, t);
    for (int i = 0; i < n; i++)
    {
        if (l[i].title == t)
        {
            l[i].display();
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "Book not found" << endl;
    }
}

void library::searchauthor(library l[], int n)
{
    string a;
    int flag = 0;
    cout << "Enter the author of the book you want to search: " << endl;
    fflush(stdin);
    getline(cin, a);
    for (int i = 0; i < n; i++)
    {
        if (l[i].author == a)
        {
            l[i].display();
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "Book not found" << endl;
    }
}

int main()
{
    int n, count = 0;
    library l[100];
    cout << "Enter the number of books you want to enter: " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        count++;
        l[i].getdata();
    }
    int ch;
    do
    {
        cout << "\nEnter your choice: " << endl;
        cout << "1. Insert book record" << endl;
        cout << "2. Search book record based on title" << endl;
        cout << "3. Search book record based on author" << endl;
        cout << "4. Display all the book records" << endl;
        cout << "5. Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:            
            l[count].getdata();
            count++;
            break;
        case 2:
            l[0].searchtitle(l, n);
            break;
        case 3:
            l[0].searchauthor(l, n);
            break;
        case 4:
            for (int i = 0; i < count; i++)
                l[i].display();
            break;
        case 5:
            break;
        default:
            cout << "Invalid choice" << endl;
        }
    } while (ch != 5);
    return 0;
}
