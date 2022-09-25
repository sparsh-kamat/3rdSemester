// convert decimal to binary using stack array
#include <stdio.h>
#include <stdlib.h>
#define max 10

int isFull(int top)
{
    if (top == max - 1)
        return 1;
    else
        return 0;
}

int isEmpty(int top)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void push(int *stack, int *top, int item)
{
    if (isFull(*top))
    {
        printf("\nStack Overflow");
        return;
    }
    (*top)++;
    stack[*top] = item;
}

int pop(int *stack, int *top)
{
    int item;
    if (isEmpty(*top))
    {
        printf("\nStack Underflow");
        return -1;
    }
    item = stack[*top];
    (*top)--;
    return item;
}

void decimaltobinary(int n)
{
    int stack[max], top = -1, rem;
    while (n != 0)
    {
        rem = n % 2;
        push(stack, &top, rem);
        n = n / 2;
    }
    while (!isEmpty(top))
    {
        rem = pop(stack, &top);
        printf("\n%d", rem);
    }
}

void binarytodecimal(int n)
{
    int stack[max], top = -1, rem, i = 0, sum = 0;
    while (n != 0)
    {
        rem = n % 10;
        push(stack, &top, rem);
        n = n / 10;
    }
    while (!isEmpty(top))
    {
        rem = pop(stack, &top);
        sum = sum + rem * pow(2, i);
        i++;
    }
    printf("\n%d", sum);
}

void decimaltohexadecimal(int n)
{
    int stack[max], top = -1, rem;
    while (n != 0)
    {
        rem = n % 16;
        push(stack, &top, rem);
        n = n / 16;
    }
    printf("\n");
    while (!isEmpty(top))
    {
        rem = pop(stack, &top);
        if (rem < 10)
            printf("%d", rem);
        else
            printf("%c", rem + 55);
    }
}

void hexadecimaltodecimal(int n)
{
    int stack[max], top = -1, rem, i = 0, sum = 0;
    while (n != 0)
    {
        rem = n % 10;
        push(stack, &top, rem);
        n = n / 10;
    }
    while (!isEmpty(top))
    {
        rem = pop(stack, &top);
        sum = sum + rem * pow(16, i);
        i++;
    }
    printf("\n%d", sum);
}

void octaltodecimal(int n)
{
    int stack[max], top = -1, rem, i = 0, sum = 0;
    while (n != 0)
    {
        rem = n % 10;
        push(stack, &top, rem);
        n = n / 10;
    }
    while (!isEmpty(top))
    {
        rem = pop(stack, &top);
        sum = sum + rem * pow(8, i);
        i++;
    }
    printf("\n%d", sum);
}

void decimaltooctal(int n)
{
    int stack[max], top = -1, rem;
    while (n != 0)
    {
        rem = n % 8;
        push(stack, &top, rem);
        n = n / 8;
    }
    while (!isEmpty(top))
    {
        rem = pop(stack, &top);
        printf("\n%d", rem);
    }
}

int main()
{
    int n, ch;
    printf("\nEnter the number: ");
    scanf("%d", &n);
    printf("\n1. Decimal to Binary");
    printf("\n2. Decimal to Octal");
    printf("\n3. Decimal to Hexadecimal");
    printf("\n4. Binary to Decimal");
    printf("\n5. Octal to Decimal");
    printf("\n6. Hexadecimal to Decimal");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        decimaltobinary(n);
        break;
    case 2:
        decimaltooctal(n);
        break;
    case 3:
        decimaltohexadecimal(n);
        break;
    case 4:
        binarytodecimal(n);
        break;
    case 5:
        octaltodecimal(n);
        break;
    case 6:
        hexadecimaltodecimal(n);
        break;
    default:
        printf("\nInvalid choice");
        break;
    }
    return 0;
}
