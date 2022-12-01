#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert(int data)
{
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Memory not available\n");
        return;
    }
    tmp->info = data;
    tmp->link = NULL;
    if (front == NULL)
        front = tmp;
    else
        rear->link = tmp;
    rear = tmp;
}

int del()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    struct node *tmp = front;
    int item = tmp->info;
    front = front->link;
    free(tmp);
    return item;
}

void display()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    struct node *tmp = front;
    printf("Queue: ");
    while (tmp != NULL)
    {
        printf("%d ", tmp->info);
        tmp = tmp->link;
    }
    printf("\n");
}

int peek()
{
    if (front == NULL)
    {
        printf("Queue underflow\n");
        exit(1);
    }
    return front->info;
}

int main()
{
    int choice, a;
    do
    {
        printf("\nEnter\n1: Insert an element\n");
        printf("2: Delete an element\n");
        printf("3: Display the peek element\n");
        printf("4: Display all the elements of the queue\n");
        printf("5: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to be added: ");
            scanf("%d", &a);
            insert(a);
            break;

        case 2:
            printf("Deleted element: %d", del());
            break;

        case 3:
            printf("Peek element is %d", peek());
            break;

        case 4:
            display();
            break;

        case 5:
            break;
        }
    } while (choice != 5);

    return 0;
}