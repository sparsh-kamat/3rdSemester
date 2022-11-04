// base converter menu driven recursive functions
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

int search(struct node *head, int item,int position)
{
    if (head == NULL)
        return -1;
    if (head->data == item)
        return position;
    return search(head->next, item, position + 1);
}

int decToBin(int n);
int decToOct(int n);
void dectohex(int n);

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

char *reverse(char *str)
{
    if (*str == '\0')
        return str;
    else
    {
        reverse(str + 1);
        printf("%c", *str);
    }
}

int main()
{
    int choice, n, i, j, k, l, m, o;
    char hex[100];
    while (1)
    {
        printf("\nEnter your choice:");
        printf("\n1. Base Converter");
        printf("\n2. GCD");
        printf("\n3. Tower of Hanoi");
        printf("\n4. Reverse a string");
        printf("\n5. Search an element");
        printf("\n6. Exit");
        printf("\nYour choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter your choice:");
            printf("\n1. Decimal to Binary");
            printf("\n2. Decimal to Octal");
            printf("\n3. Decimal to Hexadecimal");        
            printf("\nYour choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("\nEnter a decimal number: ");
                scanf("%d", &n);
                printf("\nBinary equivalent: %d", decToBin(n));
                break;
            case 2:
                printf("\nEnter a decimal number: ");
                scanf("%d", &n);
                printf("\nOctal equivalent: %d", decToOct(n));
                break;
            case 3:
                printf("\nEnter a decimal number: ");
                scanf("%d", &n);
                dectohex(n);
                break;
            }
            break;
        case 2:
            printf("\nEnter two numbers: ");
            scanf("%d %d", &i, &j);
            printf("\nGCD of %d and %d is %d", i, j, gcd(i, j));
            break;
        case 3:
            printf("\nEnter the number of disks: ");
            scanf("%d", &k);
            towerOfHanoi(k, 'A', 'C', 'B');
            break;
        case 4:
            printf("\nEnter a string: ");
            char str[100];
            scanf("%s", str);
            printf("\nReverse of the string is: ");
            reverse(str);
            break;
        case 5:
            printf("\nEnter the number of elements: ");
            scanf("%d", &l);
            printf("\nEnter the elements: ");
            for (m = 0; m < l; m++)
            {
                scanf("%d", &n);
                insert(n);
            }
            printf("\nEnter the element to be searched: ");
            scanf("%d", &o);
            int pos = search(head, o, 1);
            if (pos == -1)
                printf("\nElement not found");
            else
                printf("\nElement found at position %d", pos);
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}

int decToBin(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 2 + 10 * decToBin(n / 2));
}

int decToOct(int n)
{
    if (n == 0)
        return 0;
    else
        return (n % 8 + 10 * decToOct(n / 8));
}

void dectohex(int n){
    //recursive
    if(n==0)
        return;
    else{
        dectohex(n/16);
        if(n%16<10)
            printf("%d",n%16);
        else
            printf("%c",n%16+55);
    }
}


