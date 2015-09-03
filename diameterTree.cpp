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
int height(struct node *root)
{
	if(root==NULL)
		return 0;
	return 1 + max(height(root->left),height(root->right));
}
int width(struct node *root)
{
	if(root==NULL)
		return 0;
	int lheight = height(root->left);
	int rheight = height(root->right);

	return max(lheight+rheight+1,max(width(root->left),width(root->right)));
}
int main()
{
	struct node *root  = newNode(100);
    root->left         = newNode(50);
    root->right        = newNode(300);
    root->left->left   = newNode(20);
    root->left->right  = newNode(70);

    cout<<"Diamterer = "<<width(root)<<endl;
    return 0;
}