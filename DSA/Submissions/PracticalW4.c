/*using linked list,stacks and queue  convert postfix to infix*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
{
    char data;
    struct node *next;
};

struct node *head=NULL;

void push(char data)
{
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}

char pop()
{
    char data;
    struct node *temp=head;
    if(head==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        data=temp->data;
        head=head->next;
        free(temp);
    }
    return data;
}

int main()
{
    char postfix[100],infix[100];
    int i=0,j=0;
    printf("Enter the postfix expression: ");
    scanf("%s",postfix);
    while(postfix[i]!='\0')
    {
        if(isalpha(postfix[i]))
        {
            infix[j]=postfix[i];
            j++;
        }
        else
        {
            infix[j]=')';
            j++;
            infix[j]=pop();
            j++;
            infix[j]=postfix[i];
            j++;
            infix[j]=pop();
            j++;
            infix[j]='(';
            j++;
        }
        i++;
    }
    infix[j]='\0';
    printf("The infix expression is: %s",infix);
    return 0;
}

