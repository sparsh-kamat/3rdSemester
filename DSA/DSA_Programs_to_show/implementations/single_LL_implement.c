oiouytr#include <stdio.h>
#include <stdlib.h>

// defining the structure of the node
struct node
{
    int data;
    struct node *link;
};

// creation of linked list
struct node *create_linked_list(struct node *start)
{
    struct node *temp, *p;
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d\n", &n);
    start = NULL;
    if (n == 0)
        return start;
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data for node %d: ", i + 1);
        scanf("%d", &temp->data);
        temp->link = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->link != NULL)
                p = p->link;
            p->link = temp;
        }
    }
    return start;
};

// display the linked list
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
        p = p->link;
    }
    printf("\n");
};

// count the number of nodes in the linked list
int count_nodes(struct node *start)
{
    struct node *p;
    int count = 0;
    p = start;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
};

// insert a node at the beginning of the linked list
struct node *insert_at_beginning(struct node *start)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the node: \n");
    scanf("%d", &temp->data);
    temp->link = start;
    start = temp;
    return start;
};

// insert a node at the end of the linked list
struct node *insert_at_end(struct node *start)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data for the node:\n ");
    scanf("%d", &temp->data);
    temp->link = NULL;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    return start;
};

// insert a node at a given position in the linked list
struct node *insert_at_position(struct node *start)
{
    struct node *temp, *p;
    int pos, i;
    printf("Enter the position:\n ");
    scanf("%d", &pos);
    int count = count_nodes(start);
    if (pos > count + 1 || pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }
    if (pos == 1)
        start = insert_at_beginning(start);
    else if (pos == count + 1)
        start = insert_at_end(start);
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data for the node: \n");
        scanf("%d", &temp->data);
        p = start;
        for (i = 1; i < pos - 1; i++)
            p = p->link;
        temp->link = p->link;
        p->link = temp;
    }
    return start;
};

// delete a node from the beginning of the linked list
struct node *delete_from_beginning(struct node *start)
{
    struct node *temp;
    temp = start;
    start = start->link;
    free(temp);
    return start;
};

// delete a node from the end of the linked list
struct node *delete_from_end(struct node *start)
{
    struct node *temp, *p;
    p = start;
    while (p->link != NULL)
    {
        temp = p;
        p = p->link;
    }
    temp->link = NULL;
    free(p);
    return start;
};

// delete a node from a given position in the linked list
struct node *delete_from_position(struct node *start)
{
    struct node *temp, *p;
    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);
    int count = count_nodes(start);
    if (pos > count || pos < 1)
    {
        printf("Invalid position\n");
        return start;
    }
    if (pos == 1)
        start = delete_from_beginning(start);
    else if (pos == count)
        start = delete_from_end(start);
    else
    {
        p = start;
        for (i = 1; i < pos - 1; i++)
            p = p->link;
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }
    return start;
};

// reverse the linked list
struct node *reverse_linked_list(struct node *start)
{
    struct node *prev, *next, *p;
    p = start;
    prev = NULL;
    while (p != NULL)
    {
        next = p->link;
        p->link = prev;
        prev = p;
        p = next;
    }
    start = prev;
    return start;
};

// main function
int main()
{
    struct node *start = NULL;
    int choice;
    while (1)
    {
        printf("1. Create linked list\n");
        printf("2. Display linked list\n");
        printf("3. Count the number of nodes\n");
        printf("4. Insert a node at the beginning\n");
        printf("5. Insert a node at the end\n");
        printf("6. Insert a node at a given position\n");
        printf("7. Delete a node from the beginning\n");
        printf("8. Delete a node from the end\n");
        printf("9. Delete a node from a given position\n");
        printf("10. Reverse the linked list\n");
        printf("11. Exit\n");
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
            printf("Number of nodes in the linked list is: %d\n", count_nodes(start));
            break;
        case 4:
            start = insert_at_beginning(start);
            break;
        case 5:
            start = insert_at_end(start);
            break;
        case 6:
            start = insert_at_position(start);
            break;
        case 7:
            start = delete_from_beginning(start);
            break;
        case 8:
            start = delete_from_end(start);
            break;
        case 9:
            start = delete_from_position(start);
            break;
        case 10:
            start = reverse_linked_list(start);
            break;
        case 11:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
