//check parantheses in a given expression
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

int main()
{
    char stack[max], exp[20], item;
    int top = -1, i, flag = 0;
    printf("\nEnter the expression:");
    scanf("%s", exp);
    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(stack, &top, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(top))
            {
                flag = 1;
                break;
            }
            else
            {
                item = pop(stack, &top);
                if (exp[i] == ')' && (item == '{' || item == '['))
                {
                    flag = 1;
                    break;
                }
                if (exp[i] == '}' && (item == '(' || item == '['))
                {
                    flag = 1;
                    break;
                }
                if (exp[i] == ']' && (item == '(' || item == '{'))
                {
                    flag = 1;
                    break;
                }
            }
        }
    }
    if (flag == 1 || !isEmpty(top))
        printf("\nInvalid Expression");
    else
        printf("\nValid Expression");
    return 0;
}
