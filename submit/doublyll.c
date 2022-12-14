#include <stdio.h>
#include <stdlib.h>

struct node    
{
    int data;
    struct node *prev;
    struct node *next;
};

// add to empty
struct node *add_to_empty(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    start = temp;
    return start;
};

// add at beg
struct node *add_at_beg(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = start;
    start->prev = temp;
    start = temp;
    return start;
};

// add at end
struct node *add_at_end(struct node *start, int data)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    p = start;
    while (p->next != NULL)
        p = p->next;
    p->next = temp;
    temp->prev = p;
    temp->next = NULL;
    return start;
};

// add before
struct node *add_before(struct node *start, int data, int item)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    p = start;
    while (p != NULL)
    {
        if (p->data == item)
        {
            temp->prev = p->prev;
            temp->next = p;
            if (p->prev != NULL)
                p->prev->next = temp;
            p->prev = temp;
            return start;
        }
        p = p->next;
    }
    printf("%d not present in the list\n", item);
    return start;
};

// add after
struct node *add_after(struct node *start, int data, int item)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    p = start;
    while (p != NULL)
    {
        if (p->data == item)
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
    printf("%d not present in the list", item);
    return start;
};

// delete
struct node *del(struct node *start, int data)
{
    struct node *temp;
    if (start == NULL)
    {
        printf("List is empty");
        return start;
    }
    if (start->next == NULL)
    {
        if (start->data == data)
        {
            temp = start;
            start = NULL;
            free(temp);
            return start;
        }
        else
        {
            printf("Element %d not found", data);
            return start;
        }
    }
    if (start->data == data)
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        return start;
    }
    temp = start->next;
    while (temp->next != NULL)
    {
        if (temp->data == data)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            return start;
        }
        temp = temp->next;
    }
    if (temp->data == data)
    {
        temp->prev->next = NULL;
        free(temp);
        return start;
    }
    printf("Element %d not found", data);
    return start;
};

// display
void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is empty");
        return;
    }
    p = start;
    printf("List is : ");
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf(" ");
};

// count
void count(struct node *start)
{
    struct node *p;
    int cnt = 0;
    p = start;
    while (p != NULL)
    {
        p = p->next;
        cnt++;
    }
    printf("Number of elements are %d", cnt);
};

// search
struct node *search(struct node *start, int data)
{
    struct node *p;
    int pos = 1;
    p = start;
    while (p != NULL)
    {
        if (p->data == data)
        {
            printf("Item %d found at position %d", data, pos);
            return start;
        }
        p = p->next;
        pos++;
    }
    printf("Item %d not found in list", data);
    return start;
};

// create
struct node *create_list(struct node *start)
{
    int i, n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    start = add_to_empty(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        start = add_at_end(start, data);
    }
    return start;
};

// reverse
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
    printf("List reversed");
    return start;
};

// main
int main()
{
    struct node *start = NULL;
    int choice, data, item;
    while (1)
    {
        printf("\n1.Create List\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Add at beginning\n");
        printf("6.Add at end\n");
        printf("7.Add before node\n");
        printf("8.Add after node\n");
        printf("9.Delete\n");
        printf("10.Reverse\n");
        printf("11.Quit\n");
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
            count(start);
            break;
        case 4:
            printf("Enter the element to be searched : ");
            scanf("%d", &data);
            start = search(start, data);
            break;
        case 5:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = add_at_beg(start, data);
            break;
        case 6:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = add_at_end(start, data);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to insert : ");
            scanf("%d", &item);
            start = add_before(start, data, item);
            break;
        case 8:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to insert : ");
            scanf("%d", &item);
            start = add_after(start, data, item);
            break;
        case 9:
            printf("Enter the element to be deleted : ");
            scanf("%d", &data);
            start = del(start, data);
            break;
        case 10:
            start = reverse(start);
            break;
        case 11:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
};
