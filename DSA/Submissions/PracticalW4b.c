#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct node
{
    char info[50];
    struct node *link;
};

struct node *top = NULL;

void push(char data[])
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL)
    {
        printf("Stack ovreflow\n");
        return;
    }
    strcpy(tmp->info, data);
    tmp->link = NULL;
    if (top == NULL)
    {
        top = tmp;
        return;
    }
    tmp->link = top;
    top = tmp;
}

void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    struct node *tmp = top;
    top = tmp->link;
    free(tmp);
}

int count_nodes()
{
    struct node *tmp = top;
    int count = 0;
    while (tmp != NULL)
    {
        count++;
        tmp = tmp->link;
    }
    return count;
}
int main()
{
    char postfix[50], a, b;
    int i = 0;
    printf("Enter the postfix expression: ");
    scanf("%s", postfix);
    while (postfix[i] != '\0')
    {
        if (isalnum(postfix[i]))
        {
            char p[2];
            p[0] = postfix[i];
            p[1] = '\0';
            push(p);
        }
        else
        {
            if (count_nodes() < 2)
            {
                printf("Not enough nodes\n");
                return 0;
            }
            char op[2];
            op[0] = postfix[i];
            op[1] = '\0';
            char a[50];
            char b[50] = "(";
            strcpy(a, top->info);
            pop();
            strcat(b, top->info);
            pop();
            strcat(b, op);
            strcat(b, a);
            strcat(b, ")");
            push(b);
        }
        i++;
    }
    if (count_nodes() > 1)
        printf("There are more values\n");
    else
    {
        printf("Infix expression: ");
        printf("\n%s", top->info);
    }
    return 0;
}
