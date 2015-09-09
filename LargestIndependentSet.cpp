#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	int liss;
	struct node *left,*right;
};
int LISS(struct node *root)
{
	if(root==NULL)
		return 0;
	if(root->liss)
		return root->liss;
	if(root->left==NULL && root->right==NULL)
	{
		root->liss = 1;
		return root->liss;
	}
	int excl = LISS(root->left) + LISS(root->right);
	int incl = 1;
	if(root->left)
		incl += LISS(root->left->left) + LISS(root->left->right);
	if(root->right)
		incl += LISS(root->right->left) + LISS(root->right->right);

	return max(incl,excl);
}
struct node* newNode( int data )
{
    struct node* temp = (struct node *) malloc( sizeof(struct node) );
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
int main()
{
    struct node *root         = newNode(20);
    root->left                = newNode(8);
    root->left->left          = newNode(4);
    root->left->right         = newNode(12);
    root->left->right->left   = newNode(10);
    root->left->right->right  = newNode(14);
    root->right               = newNode(22);
    root->right->right        = newNode(25);
 
    cout<<"Size of the Largest Independent Set is "<<LISS(root)<<endl;
 
    return 0;
}