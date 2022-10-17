#include<stdio.h>
#include<stdlib.h>
#define MAX 5

void insert(int item, int *front, int *rear, int queue[])
{
    if (*rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
    *rear = *rear + 1;
    queue[*rear] = item;
}

int delete(int *front, int *rear, int queue[])
{
    int item;
    if (*front > *rear)
    {
        printf("Queue Underflow\n");
        exit(1);
    }
    item = queue[*front];
    *front = *front + 1;
    return item;
}

void display(int *front, int *rear, int queue[])
{
    int i;
    if (*front > *rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue is: \n");
    for (i = *front; i <= *rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main()
{
    int queue[MAX], front, rear, item, choice;
    front = 0;
    rear = -1;
    while (1)
    {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted: ");
            scanf("%d", &item);
            insert(item, &front, &rear, queue);
            break;
        case 2:
            item = delete(&front, &rear, queue);
            printf("Item deleted is: %d\n", item);
            break;
        case 3:
            display(&front, &rear, queue);
            break;
        case 4:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}
