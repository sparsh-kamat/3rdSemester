/*
create a structure called library to hold accession number acc,title of the book,author name,
price of the book and a flag indicating whether the book is issued or not
Write a menu driven program that implements the wrking of the library and the menu options should be as follows
1add book info
2display boook info
3issue a book based on its title
4return a book if it has been issued
5list books of a given author
6list count of books in library
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct library
{
    int number;
    char *title;
    char *author;
    int price;
    int issued;
};

void inputbooks(struct library *book)
{
    fflush(stdin);
    printf("Enter accession number of book: ");
    scanf("%d", &book->number);
    getchar();

    printf("Enter price: ");
    scanf("%d", &book->price);
    getchar();

    book->issued = 0;

    printf("Enter title: ");
    book->title = (char *)malloc(sizeof(char) * 100);
    fgets(book->title, 100, stdin);
    fflush(stdin);

    printf("Enter author: ");
    book->author = (char *)malloc(sizeof(char) * 100);
    fgets(book->author, 100, stdin);
    fflush(stdin);
}

void printbooks(struct library *book)
{
    printf("\nAccession number of book: %d\n", book->number);
    printf("Title: %s", book->title);
    printf("Author: %s", book->author);
    printf("Price is %d\n", book->price);
    if (book->issued == 1)
    {
        printf("Issued : Yes\n");
    }
    else
    {
        printf("Issued : No\n");
    }
}

void issuebook(struct library *book, int count)
{
    char *title;
    int flag = 0;
    int temp;
    title = (char *)malloc(sizeof(char) * 100);
    getchar();
    printf("\nEnter title of book to be issued: ");
    fgets(title, 100, stdin);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(book[i].title, title) == 0)
        {

            if (book[i].issued == 1)
            {
                printf("This book had already been issued\n");
            }
            else
            {
                printf("%s has now been issued\n", book[i].title);
                book[i].issued = 1;
                temp = i;
            }
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Book not found\n");
    }
}

void returnbook(struct library *book, int count)
{
    char *title;
    int flag = 0;
    title = (char *)malloc(sizeof(char) * 100);
    getchar();
    printf("\nEnter title of book to be returned: ");
    fgets(title, 100, stdin);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(book[i].title, title) == 0)
        {
            if (book[i].issued == 0)
            {
                printf("This book is not issued yet\n");
            }
            else
            {
                printf("%s has now been returned\n", book[i].title);
                book[i].issued = 0;
            }
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Book not found\n");
    }
}

void searchbooks(struct library *book, int count)
{
    char *title;
    int flag = 0;
    title = (char *)malloc(sizeof(char) * 100);
    getchar();
    printf("\nEnter title of book to be searched: ");
    fgets(title, 100, stdin);
    for (int i = 0; i < count; i++)
    {
        if (strcmp(book[i].title, title) == 0)
        {
            printbooks(&book[i]);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("Book not found\n");
    }
}

int choicee()
{
    int choice;
    printf("\n1.Insert a book record\n");
    printf("2.Display all book records\n");
    printf("3.Issue a Book\n");
    printf("4.Return a Book\n");
    printf("5.Search Book on author\n");
    printf("6. List count of books\n");
    printf("7. Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}

void menu(struct library *book, int count)
{
    int choice;
    do
    {
        choice = choicee();
        switch (choice)
        {
        case 1:
            inputbooks(&book[count]);
            count++;
            break;
        case 2:
            for (int i = 0; i < count; i++)
            {
                printbooks(&book[i]);
            }
            break;
        case 3:
            issuebook(book, count);
            break;
        case 4:
            returnbook(book, count);
            break;
        case 5:
            searchbooks(book, count);
            break;
        case 6:
            printf("The total books are %d\n", count);
            break;
        case 7:
            break;
        default:
            printf("\nInvalid choice");
            break;
        }
    } while (choice != 7);
}

int main()
{
    int count = 0;
    struct library book[100];
    menu(book, count);
    return 0;
}