#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert(int item, int front, int rear, int queue[])
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    rear++;
    queue[rear] = item;
}

int delete(int front, int rear, int queue[])
{
    int item;
    if (front == rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    front++;
    item = queue[front];
    return item;
}

void display(int front, int rear, int queue[])
{
    int i;
    if (front == rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("\nQueue is: ");
    for (i = front + 1; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int queue[MAX], front, rear, item, choice;
    front = rear = -1;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted : ");
            scanf("%d", &item);
            insert(item, front, rear, queue);
            break;
        case 2:
            item = delete(front, rear, queue);
            printf("Deleted item is  %d\n", item);
            break;
        case 3:
            display(front, rear, queue);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice\n");
        } 
    }    
} 