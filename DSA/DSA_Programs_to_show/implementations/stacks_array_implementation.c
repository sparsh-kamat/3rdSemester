#include <stdio.h>
#include <stdlib.h>
#define MAX 5

void push(int item, int top, int stack[])
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}

int pop(int top, int stack[])
{
    int item;
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    item = stack[top];
    top--;
    return item;
}

void display(int top, int stack[])
{
    int i;
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nStack is: ");
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}


int peek(int top, int stack[])
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack[top];
}

int main()
{
    int stack[MAX], top, item, choice;
    top = -1;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be pushed: ");
            scanf("%d", &item);
            push(item, top, stack);
            break;
        case 2:
            item = pop(top, stack);
            printf("Popped item is: %d\n", item);
            break;
        case 3:
            display(top, stack);
            break;
        case 4:
            printf("Item at the top is: %d\n", peek(top, stack));
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}