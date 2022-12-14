#include <stdio.h>
#include <stdlib.h>

#define max 5

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

void insert(int *queue, int *front, int *rear, int item)
{
    if (isFull(*rear))
    {
        printf("\nQueue Overflow");
        return;
    }
    if (*front == -1)
        *front = 0;
    (*rear)++;
    queue[*rear] = item;
}

int delete(int *queue, int *front, int *rear)
{
    int item;
    if (isEmpty(*front))
    {
        printf("\nQueue Underflow");
        return -1;
    }
    item = queue[*front];
    if (*front == *rear)
    {
        *front = -1;
        *rear = -1;
    }
    else
        (*front)++;
    return item;
}

int peek(int *queue, int *front, int *rear)
{
    if (isEmpty(*front))
    {
        printf("\nQueue Underflow");
        return -1;
    }
    return queue[*front];
}

void display(int *queue, int *front, int *rear)
{
    int i;
    if (isEmpty(*front))
    {
        printf("\nQueue Underflow");
        return;
    }
    printf("\nQueue elements are: ");
    for (i = *front; i <= *rear; i++)
        printf("%d ", queue[i]);
}

int main()
{
    int queue[max], front = -1, rear = -1, item, choice;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted:");
            scanf("%d", &item);
            insert(queue, &front, &rear, item);
            break;
        case 2:
            item = delete (queue, &front, &rear);
            if (item == -1)
                printf("\nQueue is empty");
            else
                printf("\nDeleted item is %d", item);
            break;
        case 3:
            item = peek(queue, &front, &rear);
            if (item == -1)
                printf("\nQueue is empty");
            else
                printf("\nPeek item is %d", item);
            break;
        case 4:
            display(queue, &front, &rear);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
    return 0;
}