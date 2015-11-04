#include<bits/stdc++.h>
using namespace std;

struct node
{
	char ch;
	struct node *prev,*next;
};
void append(struct node **head,struct node **tail,char c)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->ch = c;
	temp->prev = temp->next = NULL;
	if(*head==NULL)
	{
		*head=*tail = temp;
		return;
	}
	(*tail)->next = temp;
	temp->prev = *tail;
	*tail = temp;
}
void remove(struct node **head,struct node **tail,struct node *temp)
{
	if(*head==NULL)
		return;
	if(*head==temp)
		*head = (*head)->next;
	if(*tail==temp)
		*tail = (*tail)->prev;
	if(temp->next)
		temp->next->prev = temp->prev;
	if(temp->prev)
		temp->prev->next = temp->next;
	delete(temp);
}
void firstNR(char s[])
{
	struct node *inDLL[256];
	struct node *head=NULL,*tail=NULL;
	bool visited[256];

	for(int i=0;i<256;i++)
	{
		inDLL[i]=NULL;
		visited[i]=false;
	}

	int i=0;
	while(s[i]!='\0')
	{
		if(visited[s[i]]==false)
		{
			if(inDLL[s[i]]==NULL)
			{
				append(&head,&tail,s[i]);
				inDLL[s[i]]=tail;
			}
			else
			{
				remove(&head,&tail,inDLL[s[i]]);
				inDLL[s[i]]=NULL;
				visited[s[i]]=true;
			}
		}
		i++;
	}
	if(head)
		cout<<head->ch<<endl;
}
int main()
{
	char s[10000];
	cin>>s;
	firstNR(s);
	return 0;
}