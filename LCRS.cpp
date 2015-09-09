#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *left;
	struct node *right;
	int data;
};

struct node* newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return(temp);
}
void printInorder(struct node *root)
{
	if(root==NULL)
		return;
	printInorder(root->left);
	printf("%d ",root->data);
	printInorder(root->right);
}
void LCRS(struct node **root)
{
	if(*root==NULL)
		return;
	LCRS(&((*root)->left));
	LCRS(&((*root)->right));

	if((*root)->left!=NULL)
	{
		(*root)->left->right = (*root)->right;
		(*root)->right=NULL;
	}
	else
	{
		(*root)->left = (*root)->right;
		(*root)->right=NULL;
	}
}
int main()
{
	struct node *root  = newNode(100);
    root->left         = newNode(50);
    root->right        = newNode(300);
    root->left->left   = newNode(20);
    root->left->right  = newNode(70);

    printf("Before LCRS\n");
    printInorder(root);
    printf("\n");

    LCRS(&root);

    printf("After LCRS\n");
    printInorder(root);
    printf("\n");
    return 0;
}