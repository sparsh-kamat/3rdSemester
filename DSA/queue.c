//implement a queue in c

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
        return;
    }
    rear->next = temp;
    rear = temp;
}

void dequeue()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
    free(temp);
}

void display()
{
    struct node *temp = front;
    if (front == NULL)
    {
        printf("Queue is empty");
        return;
    }
    printf("\nQueue is: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int choice, x;
    while (1)
    {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        }
    }
    return 0;
}

