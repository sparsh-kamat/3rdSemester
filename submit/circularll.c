#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create_linked_list(struct node *start)
{
    struct node *temp, *p;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
    return start;
};

void display_linked_list(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    p = start;
    printf("Linked list is: \n");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
};

int count_nodes(struct node *start)
{
    struct node *p;
    int count = 0;
    p = start;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
};

struct node *add_at_beginning(struct node *start)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = start;
    start = temp;
    return start;
};

struct node *add_at_end(struct node *start)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data: ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    return start;
};

// Split the linked list into two linked lists, one containing elements at even positions and other containing elements at odd positions
struct node *split_even_odd(struct node *start)
{
    struct node *p, *q, *start1, *start2;
    int pos = 0;
    p = start;
    start1 = NULL;
    start2 = NULL;
    while (p != NULL)
    {
        q = (struct node *)malloc(sizeof(struct node));
        q->data = p->data;
        q->next = NULL;
        if (pos % 2 == 0)
        {
            if (start1 == NULL)
                start1 = q;
            else
            {
                struct node *r = start1;
                while (r->next != NULL)
                    r = r->next;
                r->next = q;
            }
        }
        else
        {
            if (start2 == NULL)
                start2 = q;
            else
            {
                struct node *r = start2;
                while (r->next != NULL)
                    r = r->next;
                r->next = q;
            }
        }
        p = p->next;
        pos++;
    }
    printf("\nEven linked list is: ");
    display_linked_list(start1);
    printf("\nOdd linked list is: ");
    display_linked_list(start2);
    return start;
};

void split_even_odd_2(struct node *start)
{
    struct node *p, *q, *start1, *start2;
    p = start;
    start1 = NULL;
    start2 = NULL;
    while (p != NULL)
    {
        q = (struct node *)malloc(sizeof(struct node));
        q->data = p->data;
        q->next = NULL;
        if (p->data % 2 == 0)
        {
            if (start1 == NULL)
                start1 = q;
            else
            {
                struct node *r = start1;
                while (r->next != NULL)
                    r = r->next;
                r->next = q;
            }
        }
        else
        {
            if (start2 == NULL)
                start2 = q;
            else
            {
                struct node *r = start2;
                while (r->next != NULL)
                    r = r->next;
                r->next = q;
            }
        }
        p = p->next;
    }
    printf("Even linked list is: ");
    display_linked_list(start1);
    printf("Odd linked list is: ");
    display_linked_list(start2);
};

int main()
{
    struct node *start;
    while (1)
    {
        int choice;
        printf("\n1. Create linked list\n");
        printf("2. Display linked list\n");
        printf("3. Count nodes\n");
        printf("4. Add at beginning\n");
        printf("5. Add at end\n");
        printf("6. Split even odd\n");
        printf("7. Split even odd 2\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = create_linked_list(start);
            break;
        case 2:
            display_linked_list(start);
            break;
        case 3:
            printf("Number of nodes is: %d\n", count_nodes(start));
            break;
        case 4:
            start = add_at_beginning(start);
            break;
        case 5:
            start = add_at_end(start);
            break;
        case 6:
            start = split_even_odd(start);
            break;
        case 7:
            split_even_odd_2(start);
            break;
        case 8:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
