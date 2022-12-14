//cicular queue insert delete peek display

//circular queue using array
#include<stdio.h>
#include<stdlib.h>
#define max 5

int isFull(int front, int rear)
{
    //use %
    if((rear+1)%max==front)
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
    
    *rear = (*rear + 1) % max;
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
    else
        *front = (*front + 1) % max;
    return item;
}

void display(int front, int rear, int queue[])
{
    int i;
    if (isEmpty(front, rear))
    {
        printf("\nQueue is empty");
        return;
    }
    //use % to print
    printf("\nQueue is: ");
    for (i = front; i != rear; i = (i + 1) % max)
        printf("%d ", queue[i]);
    printf("%d", queue[i]);
}

void peek(int front, int rear, int queue[]){
    if (isEmpty(front, rear))
    {
        printf("\nQueue is empty");
        return;
    }

    printf("%d ",queue[front]);
}

int main()
{
    int queue[max], front = -1, rear = -1, item, choice;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Peek\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be inserted: ");
            scanf("%d", &item);
            insert(item, &front, &rear, queue);
            break;
        case 2:
            item = delete(&front, &rear, queue);
            if (item == -1)
                printf("\nQueue is empty");
            else
                printf("\nDeleted item is %d", item);
            break;
        case 3:
            display(front, rear, queue);
            break;
        case 4:
            peek(front,rear,queue);
            break;
        case 5:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}