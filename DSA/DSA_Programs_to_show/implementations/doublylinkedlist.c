#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *create_list(struct node *start)
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
        temp->prev = NULL;
        temp->next = NULL;
        if (start == NULL)
            start = temp;
        else
        {
            p = start;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
            temp->prev = p;
        }
    }
    return start;
};

void display(struct node *start)
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

int search(struct node *start, int item)
{
    struct node *p;
    int pos = 1;
    p = start;
    while (p != NULL)
    {
        if (p->data == item)
            return pos;
        pos++;
        p = p->next;
    }
    return -1;
};

struct node *insert_at_beg(struct node *start, int item)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = start;
    start->prev = temp;
    start = temp;
    return start;
};

struct node *insert_at_end(struct node *start, int item)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
    return start;
};

struct node *insert_at_pos(struct node *start, int item, int pos)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    if (pos == 1)
    {
        temp->prev = NULL;
        temp->next = start;
        start->prev = temp;
        start = temp;
        return start;
    }
    p = start;
    for (int i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if (p == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        temp->prev = p;
        temp->next = p->next;
        if (p->next != NULL)
            p->next->prev = temp;
        p->next = temp;
    }
    return start;
};

struct node *delete_at_position(struct node *start, int pos)

{
    struct node *p;
    int i;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (pos == 1)
    {
        p = start;
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        free(p);
        return start;
    }
    p = start;
    for (i = 1; i < pos && p != NULL; i++)
        p = p->next;
    if (p == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        free(p);
    }
    return start;
};

struct node *reverse(struct node *start)
{
    struct node *p1, *p2;
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev;
    }
    start = p1;
    printf("List reversed\n");
    return start;
};

int main()
{
    struct node *start = NULL;
    int choice, item, pos, x;
    while (1)
    {
        printf("\n1. Create List\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Insert at beginning\n");
        printf("6. Insert at end\n");
        printf("7. Insert at position\n");
        printf("8. Delete at position\n");
        printf("9. Reverse\n");
        printf("10. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        printf("\n");
        switch (choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            printf("Number of elements are %d\n", count_nodes(start));
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d", &item);
            pos = search(start, item);
            if (pos == -1)
                printf("Element %d not found in the list\n", item);
            else
                printf("Element %d found at position %d\n", item, pos);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            start = insert_at_beg(start, item);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            start = insert_at_end(start, item);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            start = insert_at_pos(start, item, pos);
            break;
        case 8:
            printf("Enter the position at which to delete : ");
            scanf("%d", &pos);
            start = delete_at_position(start, pos);
            break;
        case 9:
            start = reverse(start);
            break;
        case 10:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
