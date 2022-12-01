#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int info;
    struct node *next;
};

struct node *insert(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    if (start == NULL)
    {
        tmp->next = NULL;
        tmp->prev = NULL;
        start = tmp;
    }
    else
    {
        struct node *p = start;
        while (p->next != NULL)
            p = p->next;
        tmp->next = NULL;
        tmp->prev = p;
        p->next = tmp;
    }
    return start;
}
struct node* insert_at_beg(struct node* num, int data)
{
    struct node* tmp;
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->info = data;
    if(num == NULL)
        tmp->next = NULL;
    else
    {
        tmp->next = num;
        num->prev = tmp;
    }
    tmp->prev = NULL;
    num = tmp;
    return num;

}
struct node* sum(struct node* num1, struct node* num2, struct node* num3)
{
    num3 = NULL;
    int carry = 0;
    while(num1!=NULL || num2!= NULL || carry!=0)
    {
        int sum = 0;
        if(num1!=NULL)
        {
            sum = num1->info;
            num1 = num1->next;
        }
        if(num2!=NULL)
        {
            sum += num2->info;
            num2 = num2->next;
        }
        sum+=carry;
        num3 = insert_at_beg(num3, sum%10);
        carry = sum/10;
    }
    return num3;
}
void display1(struct node *start)
{
    if (start == NULL)
    {
        printf("Empty list\n");
        return;
    }
    struct node *p = start;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

struct node *adj_swap(struct node *start)
{
    struct node *p = start;
    struct node *tmp;
    while (p != NULL && p->next != NULL)
    {
        if (p->prev == NULL)
            start = p->next;
        else
            p->prev->next = p->next;
        tmp = p->next->next;
        p->next->next = p;
        p->next->prev = p->prev;
        p->prev = p->next;
        p->next = tmp;
        if (p->next != NULL)
            p->next->prev = p;
        p = p->next;
    }
    return start;
}

struct node *create_circular(struct node *last)
{
    int i, n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    last = NULL;
    for (i = 1; i <= n; i++)
    {
        printf("Enter the data: ");
        scanf("%d", &data);
        struct node *tmp;
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->info = data;
        if (last == NULL)
            tmp->next = tmp;
        else
        {
            tmp->next = last->next;
            last->next = tmp;
        }
        last = tmp;
    }
    return last;
}

void display2(struct node *last)
{
    struct node *p = last->next;
    while (p != last)
    {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("%d \n", last->info);
}

struct node *delete_alt (struct node *last)
{
    struct node *tmp, *p, *a;
    p = last->next;
    a = last->next;
    while (p != last)
    {
        if (p == a)
        {
            tmp = p;
            last->next = last->next->next;
        }
        else
        {
            tmp = p->next;
            if (p->next == last)
            {
                last = p;
                p->next = tmp->next;
                return last;
            }
            p->next = tmp->next;
        }
        free(tmp);
        p = p->next;
    }
    return last;
}

int main()
{
    int choice, n, data, n1, n2, a, b;
    struct node *start;
    struct node *num1;
    struct node *num2;
    struct node *num3;
    struct node *last = NULL;
    do
    {
        printf("\nEnter\n1: Swapping adjacent elements in double linked list\n");
        printf("2: Sum of two numbers using double linked list\n");
        printf("3: Delete alternate nodes in circular linked list\n");
        printf("4: Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = NULL;
            printf("Enter the number of nodes:\n");
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                printf("Enter the data: ");
                scanf("%d", &data);
                start = insert(start, data);
            }
            printf("List before swapping: ");
            display1(start);
            printf("List after swapping adjacent elements: ");
            start = adj_swap(start);
            display1(start);
            break;

        case 2:
            num1 = NULL;
            num2 = NULL;
            printf("Enter number 1: ");
            scanf("%d", &n1);
            a = n1;
            while(a!=0)
            {
                int rem = a%10;
                num1 = insert(num1, rem);
                a = a/10;
            }
            printf("Number 1 in reverse order: ");
            display1(num1);
            printf("Enter number 2: ");
            scanf("%d", &n2);
            b = n2;
            while(b!=0)
            {
                int rem = b%10;
                num2 = insert(num2, rem);
                b = b/10;
            }
            printf("Number 2 in reverse order: ");
            display1(num2);
            num3 = sum(num1, num2, num3);
            printf("Sum of the numbers: ");
            display1(num3);
            break;

        case 3:
            last = create_circular(last);
            printf("List before deleting: ");
            display2(last);
            last = delete_alt (last);
            printf("List after deleting alternate nodes: ");
            display2(last);
            break;
            
        }
    } while (choice != 4);
}