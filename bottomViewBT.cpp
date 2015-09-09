#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *left;
	struct node *right;
	int data;
	int hd;
};
struct node* newNode(int data)
{
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
 
    return(temp);
}
void bottomViewBT(struct node *root)
{
	queue<struct node *> q;
	map<int, struct node *>  m;
	map<int, struct node *>  ::  iterator it;

	struct node *temp;

	int hd=0;
	root->hd = 0;
	q.push(root);
	while(!q.empty())
	{
		temp = q.front();
		q.pop();
		m[temp->hd] = temp;
		if(temp->left)
		{
			temp->left->hd = temp->hd-1;
			q.push(temp->left);
		}
		if(temp->right)
		{
			temp->right->hd = temp->hd+1;
			q.push(temp->right);
		}
	}
	for(it=m.begin();it!=m.end();it++)
		cout<<it->second->data<<" ";
	cout<<endl;
}
int main()
{
	struct node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(5);
    root->left->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(25);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    bottomViewBT(root);
    return 0;
}