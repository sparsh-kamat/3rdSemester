#include<stdio.h>
#include<stdlib.h>
typedef enum {false, true} boolean;

struct node 
{
	struct node *left;
	boolean lthread;
	int info;
	boolean rthread;
	struct node *right;
};

struct node *in_succ(struct node *ptr)
{
	if (ptr->rthread==true)
		return ptr->right;
	else{
		ptr=ptr->right;
		while(ptr->lthread==false)
			ptr=ptr->left;
		return ptr;
	}
}

struct node *in_pred(struct node *ptr)
{
	if (ptr->lthread==true)
		return ptr->left;
	else{
		ptr=ptr->left;
		while(ptr->rthread==false)
			ptr=ptr->right;
		return ptr;
	}
}

struct node * insert(struct node *root, int ikey)
{
	struct node *temp, *par=NULL, *ptr=root;
	int found=0;
	while (ptr!=NULL){
		if (ikey==ptr->info){
			found=1;
			break;
		}
		par=ptr;
		if (ikey<ptr->info){
			if (ptr->lthread==false)
				ptr=ptr->left;
			else
				break;
		}
		else{
			if (ptr->rthread==false)
				ptr=ptr->right;
			else
				break;
		}
	}
	if (found)
		printf("Duplicate key");
	else{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->info=ikey;
		temp->lthread=true;
		temp->rthread=true;
		if (par==NULL){
			root=temp;
			temp->left=NULL;
			temp->right=NULL;
		}
		else if (ikey<par->info){
			temp->left=par->left;
			temp->right=par;
			par->lthread=false;
			par->left=temp;
		}
		else{
			temp->left=par;
			temp->right=par->right;
			par->rthread=false;
			par->right=temp;
		}
	}
	return root;
}

void inorder(struct node *root)
{
	struct node *ptr;
	if (root==NULL){
		printf("Tree is empty");
		return;
	}
	ptr=root;
	while (ptr->lthread==false)
		ptr=ptr->left;
	while (ptr!=NULL){
		printf("%d ", ptr->info);
		ptr=in_succ(ptr);
	}
}

struct node * case_a(struct node *root, struct node *par, struct node *ptr){
	if (par==NULL)
		root=NULL;
	else if (ptr==par->left){
		par->lthread=true;
		par->left=ptr->left;
	}
	else{
		par->rthread=true;
		par->right=ptr->right;
	}
	free(ptr);
	return root;
}

struct node * case_b(struct node *root, struct node *par, struct node *ptr){
	struct node *child, *s, *p;
	if (ptr->lthread==false)
		child=ptr->left;
	else
		child=ptr->right;
	if (par==NULL)
		root=child;
	else if (ptr==par->left)
		par->left=child;
	else
		par->right=child;
	s=in_succ(ptr);
	p=in_pred(ptr);
	if (ptr->lthread==false)
		ptr->right=s;
	else{
		if (ptr->rthread==false)
			s->left=p;
	}
	free(ptr);
	return root;
}

struct node * case_c(struct node *root, struct node *par, struct node *ptr)
{
	struct node *succ, *parsucc;
	parsucc=ptr;
	succ=ptr->right;
	while(succ->left!=NULL){
		parsucc=succ;
		succ=succ->left;
	}
	ptr->info=succ->info;
	if (succ->lthread==true && succ->rthread==true)
		root=case_a(root, parsucc, succ);
	else
		root=case_b(root, parsucc, succ);
	return root;
}

struct node * del(struct node *root, int dkey)
{
	struct node *par, *ptr;
	int found=0;
	ptr=root; 
	par=NULL;
	while (ptr!=NULL){
		if (dkey==ptr->info){
			found=1;
			break;
		}
		par=ptr;
		if (dkey<ptr->info){
			if (ptr->lthread==false)
				ptr=ptr->left;
			else
				break;
		}
		else{
			if (ptr->rthread==false)
				ptr=ptr->right;
			else
				break;
		}
	}
	if (found==0)
		printf("dkey not present in tree");
	else if (ptr->lthread==false && ptr->rthread==false)
		root=case_c(root, par, ptr);
	else if (ptr->lthread==false)
		root=case_b(root, par, ptr);
	else if (ptr->rthread==false)
		root=case_b(root, par, ptr);
	else
		root=case_a(root, par, ptr);
	return root;
}

struct node * search(struct node *ptr, int key)
{
	if (ptr==NULL){
		printf("Element not found");
		return ptr;
	} 
	else if (key<ptr->info)
		return search(ptr->left, key);
	else if (key>ptr->info)
		return search(ptr->right, key);
	else{
		printf("Element found");
		return ptr;
	}
}

int main()
{
	int i, choice, num, arr[7]={50, 30, 70, 20, 40, 60, 80};
	struct node *root=NULL;
	for (i=0; i<7; i++)
		root=insert(root, arr[i]);
	printf("Inorder traversal of given tree: ");
	inorder(root);
	
	while (1){
		printf("\n1. Insert an element\n");
		printf("2. Delete an element\n");
		printf("3. Search for element\n");
		printf("4. Inorder traversal\n");
		printf("5. Quit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				printf("Enter element to be inserted: ");
				scanf("%d", &num);
				root=insert(root, num);
				break;
				
			case 2:
				printf("Enter element to be deleted: ");
				scanf("%d", &num);
				root=del(root, num);
				break;
				
			case 3:
				printf("Enter element to be searched: ");
				scanf("%d", &num);
				root=search(root, num);
				break;
				
			case 4:
				inorder(root);
				printf("\n");
				break;
				
			case 5:
				exit(1);
				
			default:
				printf("Wrong choice");
				
		}
	}
}