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
void storeInorder(int a[],struct node *root,int *i)
{
	if(root==NULL);
		return;
	storeInorder(a,root->left,i);
	a[*i] = root->data;
	(*i)++;
	storeInorder(a,root->right,i);
}
void merge(int a1[],int a2[],int m,int n,int a3[],int *k)
{
	int i=0,j=0;
	while(i<m && j<n)
	{
		if(a1[i]<a2[j])
			a3[(*k)++] = a1[i++];
		else
			a3[(*k)++] = a2[j++];
	}
	while(i<m)
		a3[(*k)++] = a1[i++];
	while(j<n)
		a3[(*k)++] = a2[j++];

}
struct node *conBST(int a[],int low,int high)
{
	if(low>high)
		return NULL;
	int mid = (low+high)/2;
	struct node *root = newNode(a[mid]);
	root->left = conBST(a,low,mid-1);
	root->right = conBST(a,mid+1,high);

	return root;
}
struct node *mergeTrees(struct node *root1,struct node *root2,int m,int n)
{
	int *a1 = new int[m];
	int *a2 = new int[n];
	int i=0;
	storeInorder(a1,root1,&i);

	i=0;
	storeInorder(a2,root2,&i);

	int a3[m+n];
	int k=0;
	merge(a1,a2,m,n,a3,&k);

	return conBST(a3,0,k-1);
}
int main()
{
	struct node *root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);

    struct node *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);

    struct node *mergedTree = mergeTrees(root1, root2, 5, 3);
    printInorder(mergedTree);
    printf("\n");
    return 0;
}