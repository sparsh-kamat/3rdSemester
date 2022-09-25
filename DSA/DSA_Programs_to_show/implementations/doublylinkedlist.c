//implement doubly linked list in C. Do not declare any global variables.
//have functions to insert, delete, display, count nodes, search, reverse the list.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *prev;
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

struct node *insert_after(struct node *start, int item, int x)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            temp->prev = p;
            temp->next = p->next;
            if (p->next != NULL)
                p->next->prev = temp;
            p->next = temp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", x);
    return start;
};

struct node *insert_before(struct node *start, int item, int x)
{
    struct node *temp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (x == start->data)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = item;
        temp->prev = NULL;
        temp->next = start;
        start->prev = temp;
        start = temp;
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->data = item;
            temp->prev = p->prev;
            temp->next = p;
            p->prev->next = temp;
            p->prev = temp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", x);
    return start;
};

struct node *insert_at_pos(struct node *start, int item, int pos)
{
    struct node *temp, *p;
    int i;
    if (pos == 1)
        return insert_at_beg(start, item);
    p = start;
    for (i = 1; i < pos - 1 && p != NULL; i++)
        p = p->next;
    if (p == NULL)
        printf("There are less than %d elements\n", pos);
    else
        return insert_after(start, item, p->data);
    return start;
};

struct node *delete_at_beg(struct node *start)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    temp = start;
    start = start->next;
    start->prev = NULL;
    free(temp);
    return start;
};

struct node *delete_at_end(struct node *start)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    temp = start;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
    return start;
};

struct node *delete_after(struct node *start, int x)
{
    struct node *temp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            temp = p->next;
            if (temp == NULL)
            {
                printf("Element %d is the last element\n", x);
                return start;
            }
            p->next = temp->next;
            if (temp->next != NULL)
                temp->next->prev = p;
            free(temp);
            return start;
        }
        p = p->next;
    }
    printf("Element %d not present in the list\n", x);
    return start;
};

struct node *delete_before(struct node *start, int x)
{
    struct node *temp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (start->data == x)
    {
        printf("Element %d has no element before it\n", x);
        return start;
    }
    if (start->next->data == x)
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        return start;
    }
    p = start;
    while (p != NULL)
    {
        if (p->data == x)
        {
            temp = p->prev;
            temp->prev->next = p;
            p->prev = temp->prev;
            free(temp);
            return start;
        }
        p = p->next;
    }
    printf("Element %d not present in the list\n", x);
    return start;
};

struct node *delete_list(struct node *start)
{
    struct node *temp;
    if (start == NULL)
        return start;
    while (start != NULL)
    {
        temp = start;
        start = start->next;
        free(temp);
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
        printf("1. Create List\n");
        printf("2. Display\n");
        printf("3. Count\n");
        printf("4. Search\n");
        printf("5. Insert at beginning\n");
        printf("6. Insert at end\n");
        printf("7. Insert after node\n");
        printf("8. Insert before node\n");
        printf("9. Insert at position\n");
        printf("10. Delete at beginning\n");
        printf("11. Delete at end\n");
        printf("12. Delete node after\n");
        printf("13. Delete node before\n");
        printf("15. Reverse\n");
        printf("16. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        if (choice == 16)
            break;
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
            printf("Enter the element after which to insert : ");
            scanf("%d", &x);
            start = insert_after(start, item, x);
            break;
        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            printf("\nEnter the element before which to insert : ");
            scanf("%d", &x);
            start = insert_before(start, item, x);
            break;
        case 9:
            printf("Enter the element to be inserted : ");
            scanf("%d", &item);
            printf("Enter the position at which to insert : ");
            scanf("%d", &pos);
            start = insert_at_pos(start, item, pos);
            break;
        case 10:
            start = delete_at_beg(start);
            break;
        case 11:
            start = delete_at_end(start);
            break;
        case 12:
            printf("Enter the element after which to delete : ");
            scanf("%d", &x);
            start = delete_after(start, x);
            break;

        case 13:
            printf("Enter the element before which to delete : ");
            scanf("%d", &x);
            start = delete_before(start, x);
            break;
        case 15:
            start = reverse(start);
            break;
        default:
            printf("Wrong choice\n");
        }
    }
    start = delete_list(start);
    return 0;
}


