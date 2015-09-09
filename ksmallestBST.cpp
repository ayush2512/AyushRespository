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
int Ksmallest(struct node *root,int k)
{
	stack<node*> s;
	struct node *head = root,*temp;
	int result = -1;

	while(!s.empty() || head!=NULL)
	{
		if(head!=NULL)
		{
			s.push(head);
			head = head->left;
		}
		else
		{
			temp = s.top();
			s.pop();
			k--;
			if(k==0)
				result = temp->data;
			head = temp->right;
		}
	}
	return result;

}
int main()
{
	struct node *root  = newNode(100);
    root->left         = newNode(50);
    root->right        = newNode(300);
    root->left->left   = newNode(20);
    root->left->right  = newNode(70);

    printInorder(root);
    printf("\n");

    int k;
    cin>>k;
    int result = Ksmallest(root,k);
    if(result == -1)
    	cout<<"Out of index K value"<<endl;
    else
    	cout<<"Kth smallest = "<<result<<endl;
    return 0;
}