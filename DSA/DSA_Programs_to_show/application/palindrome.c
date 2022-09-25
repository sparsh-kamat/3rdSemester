//check palindrom using stack and queue array
#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 10

int isFull(int front, int rear)
{
    if ((front == rear + 1) || (front == 0 && rear == max - 1))
        return 1;
    else
        return 0;
}

int isEmpty(int front, int rear)
{
    if (front == -1)
        return 1;
    else
        return 0;
}


void enqueue(int *queue, int *front, int *rear, int item)
{
    if (isFull(*front, *rear))
    {
        printf("\nQueue Overflow");
        return;
    }
    if (*front == -1)
        *front = 0;
    if(*rear == max - 1)
        *rear = 0;
    else
        (*rear)++;
    queue[*rear] = item;
}

int dequeue(int *queue, int *front, int *rear)
{
    int item;
    if (isEmpty(*front, *rear))
    {
        printf("\nQueue Underflow");
        return -1;
    }
    item = queue[*front];
    if (*front == *rear)
        *front = *rear = -1;
    else if (*front == max - 1)
        *front = 0;
    else
        (*front)++;
    return item;
}

void push(int *stack, int *top, int item)
{
    if (*top == max - 1)
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
    if (*top == -1)
    {
        printf("\nStack Underflow");
        return -1;
    }
    item = stack[*top];
    (*top)--;
    return item;
}


void palindrome(int *queue, int *stack, int *front, int *rear, int *top)
{
    char word[max];
    int i, len, item;
    printf("\nEnter a word: ");
    scanf("%s", word);
    len = strlen(word);
    for (i = 0; i < len; i++)
    {
        if (isalpha(word[i]))
        {
            item = word[i];
            enqueue(queue, front, rear, item);
            push(stack, top, item);
        }
    }
    while (!isEmpty(*front, *rear))
    {
        if (dequeue(queue, front, rear) != pop(stack, top))
        {
            printf("\nNot a palindrome ");
            return;
        }
    }
    printf("\nPalindrome ");
}

int main()
{
    int queue[max], stack[max], front = -1, rear = -1, top = -1;
    palindrome(queue, stack, &front, &rear, &top);
    return 0;
}


