#include <stdio.h>
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
        p = p->link;
        count++;
    }
    return count;
};

// search an element in the linked list
int search(struct node *start, int item)
{
    struct node *p;
    int pos = 1;
    p = start;
    while (p != NULL)
    {
        if (p->data == item)
            return pos;
        p = p->link;
        pos++;
    }
    return -1;
};

// insert a node at the beginning of the linked list
struct node *insert_at_beg(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = start;
    start = temp;
    return start;
};

// insert a node at the end of the linked list
struct node *insert_at_end(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    temp->link = NULL;
    return start;
};

// insert a node after a given node in the linked list
struct node *insert_after(struct node *start, int data, int item)
{
    struct node *temp, *p;
    p = start;
    while (p != NULL)
    {
        if (p->data == item)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    printf("%d not present in the list\n", item);
    return start;
};

// insert a node before a given node in the linked list
struct node *insert_before(struct node *start, int data, int item)
{
    struct node *temp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (start->data == item)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = data;
        temp->link = start;
        start = temp;
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->data == item)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = data;
            temp->link = p->link;
            p->link = temp;
            return start;
        }
        p = p->link;
    }
    printf("%d not present in the list\n", item);
    return start;
};

// delete a node from the linked list
struct node *delete_node(struct node *start, int data)
{
    struct node *temp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (start->data == data)
    {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->data == data)
        {
            temp = p->link;
            p->link = temp->link;
            free(temp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found\n", data);
    return start;
};

// reverse the linked list
struct node *reverse(struct node *start)
{
    struct node *prev, *ptr, *next;
    prev = NULL;
    ptr = start;
    while (ptr != NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;
};

// insert or delete at a given position
struct node *insert_at_pos(struct node *start, int data, int pos)
{
    struct node *temp, *p;
    int i;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (pos == 1)
    {
        temp->link = start;
        start = temp;
        return start;
    }
    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->link;
    if (p == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        temp->link = p->link;
        p->link = temp;
    }
    return start;
};

struct node *delete_at_pos(struct node *start, int pos)
{
    struct node *temp, *p;
    int i;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (pos == 1)
    {
        temp = start;
        start = start->link;
        free(temp);
        return start;
    }
    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->link;
    if (p == NULL || p->link == NULL)
        printf("There are less than %d elements\n", pos);
    else
    {
        temp = p->link;
        p->link = temp->link;
        free(temp);
    }
    return start;
};

// main
int main()
{
    struct node *start = NULL;
    int choice, data, item, pos;
    while (1)
    {
        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Insert at beginning\n");
        printf("6.Insert at end\n");
        printf("7.Insert after node\n");
        printf("8.Insert before node\n");
        printf("9.Insert at position\n");
        printf("10.Delete\n");
        printf("11.Delete at position\n");
        printf("12.Reverse\n");
        printf("13.Quit\n\n");
        printf("Enter your choice : ");
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
            printf("Number of elements are %d\n", count_nodes(start));
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d", &data);
            int ss = search(start, data);
            if (ss == -1)
                printf("Element %d is not present in the list\n", data);
            else
                printf("Element %d is present at position %d\n", data, ss);
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = insert_at_beg(start, data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = insert_at_end(start, data);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            start = insert_after(start, data, item);
            break;

        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            start = insert_before(start, data, item);
            break;

        case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            start = insert_at_pos(start, data, pos);
            break;

        case 10:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            start = delete_node(start, data);
            break;

        case 11:
            printf("Enter the position of the element to be deleted : ");
            scanf("%d", &pos);
            start = delete_at_pos(start, pos);
            break;

        case 12:
            start = reverse(start);
            break;

        case 13:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}
