/*
Develop a c program to perform the following tasks
1.accept two polynomials from user
2.add the two polynomials
3.multiply the two polynomials
4.modify any of the polynomials
  a.insert
  b.delete
5.Accept polynomials from a file
Using linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int coeff;
    int power;
    struct node *next;
};

struct node *create(struct node *start,int z)
{
    struct node *temp, *p;
    printf("\nPlease Enter terms in descending order of exponent\n");
    printf("Enter the number of terms in polynomial %d: ",z);
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        printf("Enter the coefficient: ");
        scanf("%d", &temp->coeff);
        printf("Enter the power: ");
        scanf("%d", &temp->power);
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
}


void display(struct node* start)
{
    struct node *p;
    p = start;
    while (p != NULL)
    {
        printf("%dx^%d", p->coeff, p->power);
        p = p->next;
        if (p != NULL)
            printf(" + ");
    }
    printf("\n");
}

struct node *add(struct node *start1, struct node *start2)
{
    struct node *start3, *p, *q, *temp;
    start3 = NULL;
    p = start1;
    q = start2;
    while (p != NULL && q != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->next = NULL;
        if (p->power > q->power)
        {
            temp->coeff = p->coeff;
            temp->power = p->power;
            p = p->next;
        }
        else if (p->power < q->power)
        {
            temp->coeff = q->coeff;
            temp->power = q->power;
            q = q->next;
        }
        else
        {
            temp->coeff = p->coeff + q->coeff;
            temp->power = p->power;
            p = p->next;
            q = q->next;
        }
        if (start3 == NULL)
            start3 = temp;
        else
        {
            struct node *r = start3;
            while (r->next != NULL)
                r = r->next;
            r->next = temp;
        }
    }
    while (p != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = p->coeff;
        temp->power = p->power;
        temp->next = NULL;
        p = p->next;
        if (start3 == NULL)
            start3 = temp;
        else
        {
            struct node *r = start3;
            while (r->next != NULL)
                r = r->next;
            r->next = temp;
        }
    }
    while (q != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->coeff = q->coeff;
        temp->power = q->power;
        temp->next = NULL;
        q = q->next;
        if (start3 == NULL)
            start3 = temp;
        else
        {
            struct node *r = start3;
            while (r->next != NULL)
                r = r->next;
            r->next = temp;
        }
    }
    return start3;
}

struct node *multiply(struct node *start1, struct node *start2)
{
    struct node *start3, *p, *q, *temp;
    start3 = NULL;
    p = start1;
    while (p != NULL)
    {
        q = start2;
        while (q != NULL)
        {
            temp = (struct node *)malloc(sizeof(struct node));
            temp->coeff = p->coeff * q->coeff;
            temp->power = p->power + q->power;
            temp->next = NULL;
            if (start3 == NULL)
                start3 = temp;
            else
            {
                struct node *r = start3;
                while (r->next != NULL)
                    r = r->next;
                r->next = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    return start3;
}

//insert at position 
struct node *insertatpos(struct node *start, int pos, int coeff, int power)
{
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->power = power;
    temp->next = NULL;
    if (pos == 1)
    {
        temp->next = start;
        start = temp;
    }
    else
    {
        p = start;
        for (int i = 1; i < pos - 1; i++)
            p = p->next;
        temp->next = p->next;
        p->next = temp;
    }
    return start;
}

//delete at position
struct node *deleteatpos(struct node *start, int pos)
{
    struct node *p, *q;
    if (pos == 1)
    {
        p = start;
        start = start->next;
        free(p);
    }
    else
    {
        p = start;
        for (int i = 1; i < pos - 1; i++)
            p = p->next;
        q = p->next;
        p->next = q->next;
        free(q);
    }
    return start;
}

struct node *modify(struct node *start)
{
    //display the polynomial first
    printf("\nThe polynomial is: ");
    display(start);
    printf("\nDo You want to insert or delete a term? (1/2): \n");
    int ch;
    scanf("%d", &ch);
    if (ch == 1)
    {
        printf("Enter the position: ");
        int pos;
        scanf("%d", &pos);
        printf("Enter the coefficient: ");
        int coeff;
        scanf("%d", &coeff);
        printf("Enter the power: ");
        int power;
        scanf("%d", &power);
        start = insertatpos(start, pos, coeff, power);
    }
    else if (ch == 2)
    {
        printf("Enter the position: ");
        int pos;
        scanf("%d", &pos);
        start = deleteatpos(start, pos);
    }
}


int main(){
    struct node *start1 = NULL, *start2 = NULL;
    while(1){
        printf("\nEnter your choice\n");
        printf("1. Enter Polynomials\n");
        printf("2. Display Polynomials\n");
        printf("3. Add Polynomials\n");
        printf("4. Multiply Polynomials\n");
        printf("5. Modify Polynomials\n");
        printf("6. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                start1 = create(start1,1);
                start2 = create(start2,2);
                break;
            case 2:
                display(start1);
                display(start2);
                break;
            case 3:
                display(add(start1, start2));
                break;
            case 4:
                display(multiply(start1, start2));
                break;
            case 5:
                printf("Enter the polynomial to modify 1 or 2\n");
                int poly;
                scanf("%d", &poly);
                if(1)
                    modify(start1);
                else
                    modify(start2);
                break;

            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
}