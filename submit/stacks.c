//palindrome check, parantheses check, conversion given a base all conversions using stack
//stack using arrays

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void push(char *stack, int *top, char item)
{
    if (isFull(*top))
    {
        printf("\nStack Overflow");
        return;
    }
    (*top)++;
    stack[*top] = item;
}

char pop(char *stack, int *top)
{
    char item;
    if (isEmpty(*top))
    {
        printf("\nStack Underflow");
        return -1;
    }
    item = stack[*top];
    (*top)--;
    return item;
}

//palindrome check using stack
int palindrome(char *stack, int *top, char *exp)
{
    int i, flag = 0;
    for (i = 0; i < strlen(exp); i++)
    {
        push(stack, top, exp[i]);
    }
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] != pop(stack, top))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        return 0;
    else
        return 1;
}

//parantheses check using stack
int parantheses(char *stack, int *top, char *exp)
{
    int i, flag = 0;
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, top, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(*top))
            {
                flag = 1;
                break;
            }
            else
            {
                pop(stack, top);
            }
        }
    }
    if (flag == 1 || !isEmpty(*top))
        return 0;
    else
        return 1;
}

//conversion from decimal to binary using stack
void decToBin(char *stack, int *top, int num)
{
    int rem;
    while (num != 0)
    {
        rem = num % 2;
        push(stack, top, rem + '0');
        num = num / 2;
    }
    while (!isEmpty(*top))
    {
        printf("%c", pop(stack, top));
    }
}

//conversion from decimal to octal using stack
void decToOct(char *stack, int *top, int num)
{
    int rem;
    while (num != 0)
    {
        rem = num % 8;
        push(stack, top, rem + '0');
        num = num / 8;
    }
    while (!isEmpty(*top))
    {
        printf("%c", pop(stack, top));
    }
}

//conversion from decimal to hexadecimal using stack
void decToHex(char *stack, int *top, int num)
{
    int rem;
    while (num != 0)
    {
        rem = num % 16;
        if (rem < 10)
            push(stack, top, rem + '0');
        else
            push(stack, top, rem + 55);
        num = num / 16;
    }
    while (!isEmpty(*top))
    {
        printf("%c", pop(stack, top));
    }
}

int main()
{
    char stack[max], exp[20], item;
    int top = -1, i, flag = 0, num;
    while (1)
    {
        printf("\n1.Palindrome Check");
        printf("\n2.Parantheses Check");
        printf("\n3.Decimal to Binary");
        printf("\n4.Decimal to Octal");
        printf("\n5.Decimal to Hexadecimal");
        printf("\n6.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("\nEnter the expression:");
            scanf("%s", exp);
            if (palindrome(stack, &top, exp))
                printf("\nPalindrome");
            else
                printf("\nNot a Palindrome");
            break;
        case 2:
            printf("\nEnter the expression:");
            scanf("%s", exp);
            if (parantheses(stack, &top, exp))
                printf("\nValid Parantheses");
            else
                printf("\nInvalid Parantheses");
            break;
        case 3:
            printf("\nEnter the number:");
            scanf("%d", &num);
            decToBin(stack, &top, num);
            break;
        case 4:
            printf("\nEnter the number:");
            scanf("%d", &num);
            decToOct(stack, &top, num);
            break;
        case 5:
            printf("\nEnter the number:");
            scanf("%d", &num);
            decToHex(stack, &top, num);
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvalid Choice");
        }
    }