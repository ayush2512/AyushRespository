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
void reverseAlt(struct node *head)
{
	struct node *curr=head;
	while(curr!=NULL && curr->next!=NULL)
	{
		int temp = curr->data;
		curr->data = curr->next->data;
		curr->next->data = temp;
		curr = curr->next->next;
	}
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

	reverseAlt(head);
	printLL(head);

	return 0;
}