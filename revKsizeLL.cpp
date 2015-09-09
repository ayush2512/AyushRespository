#include<bits/stdc++.h>
using namespace std;

struct node
{
	struct node *next;
	int data;
};
void push(struct node **head,int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = *head;
	*head = temp;
}
void printLL(struct node *head)
{
	struct node *temp = head;
	while(temp!=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
struct node *reverseksize(struct node *head,int k)
{
	struct node *curr=head,*prev=NULL,*next=NULL;
	int count=0;
	while(curr!=NULL && count<k)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}
	if(next!=NULL)
		head->next = reverseksize(next,k);
	return prev;
}
int main()
{
	struct node *head = NULL;

	push(&head,9);
	push(&head,7);
	push(&head,5);
	push(&head,3);
	push(&head,1);

	printLL(head);

	struct node *start = reverseksize(head,3);
	printLL(start);

	return 0;
}