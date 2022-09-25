//circular queue using array
#include<stdio.h>
#include<stdlib.h>
#define max 5

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

void insert(int item, int *front, int *rear, int queue[])
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

int delete(int *front, int *rear, int queue[])
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

void display(int front, int rear, int queue[])
{
    int i;
    if (isEmpty(front, rear))
    {
        printf("Queue is empty");
        return;
    }
    printf("\nQueue is: ");
    if (front <= rear)
    {
        for (i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for (i = front; i <= max - 1; i++)
            printf("%d ", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main()
{
    int queue[max], front, rear, item, choice;
    front = rear = -1;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted : ");
            scanf("%d", &item);
            insert(item, &front, &rear, queue);
            break;
        case 2:
            item = delete(&front, &rear, queue);
            item == -1 ? printf("\nQueue is empty") : printf("\nDeleted item is %d", item);
            break;
        case 3:
            display(front, rear, queue);
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice");
        }
    }
}