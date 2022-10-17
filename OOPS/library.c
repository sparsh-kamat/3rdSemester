#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct book_record
{
    int number;
    char *subject;
    char *title;
    char *author;
};

void inputbooks(struct book_record *book)
{

    fflush(stdin);
    printf("Enter serial number of book: ");
    scanf("%d", &book->number);
    getchar();

    printf("Enter subject: ");
    book->subject = (char *)malloc(sizeof(char) * 100);
    fgets(book->subject, 100, stdin);
    fflush(stdin);

    printf("Enter title: ");
    book->title = (char *)malloc(sizeof(char) * 100);
    fgets(book->title, 100, stdin);
    fflush(stdin);

    printf("Enter author: ");
    book->author = (char *)malloc(sizeof(char) * 100);
    fgets(book->author, 100, stdin);
}

void printbooks(struct book_record *book)
{
    printf("\nSerial number of book: %d\n", book->number);
    printf("\nSubject: %s\n", book->subject);
    printf("Title: %s\n", book->title);
    printf("Author: %s\n", book->author);
}

int choicee()
{
    int choice;
    printf("\n1.Insert a book record\n2.Search book based on subject\n3.Search book based on author name\n4.Display all book records\n5.Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void insertbooks(struct book_record *book)
{
    inputbooks(book);
}

void searchbooks(struct book_record *book,int count)
{
    char *subject;
    subject = (char *)malloc(sizeof(char) * 100);
    printf("\nEnter subject of book to be searched: ");
    fflush(stdin);
    fgets(subject, 100, stdin);
    fflush(stdin);
    for (int i = 0; i < count + 1; i++)
    {
        if (strcmp(book[i].subject, subject) == 0)
        {
            printbooks(&book[i]);
        }
    }
}

void searchbooks1(struct book_record *book,int count)
{
    char *author;
    author = (char *)malloc(sizeof(char) * 100);
    printf("\nEnter author of book to be searched: ");
    fflush(stdin);
    fgets(author, 100, stdin);
    fflush(stdin);
    for (int i = 0; i < count + 1; i++)
    {
        if (strcmp(book[i].author, author) == 0)
        {
            printbooks(&book[i]);
        }
    }
}

void menu(struct book_record *book,int count)
{

    int choice;
    do
    {
        choice = choicee();
        switch (choice)
        {
        case 1:
            insertbooks(&book[count]);
            count++;
            break;
        case 2:
            searchbooks(book,count);
            break;
        case 3:
            searchbooks1(book,count);
            break;
        case 4:
            for (int i = 0; i < count + 1; i++)
            {
                printbooks(&book[i]);
            }
            break;
        case 5:
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 5);
}

int main()
{
    int count = 0;
    struct book_record book[100];
    menu(book,count);
    return 0;
}