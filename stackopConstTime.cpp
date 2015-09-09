#include<bits/stdc++.h>
using namespace std;

stack<int> s1,s2;
int minimum = -1;

void push(int x)
{
	s1.push(x);
	if(s1.size()==1 || x < minimum)
	{
		s2.push(x);
		minimum = x;
	}
}
void pop()
{
	if(s1.top() == minimum)
	{
		s2.pop();
		if(!s2.empty())
			minimum = s2.top();
		else
			minimum = -1;
	}
	s1.pop();
}
int top()
{
	return s1.top();
}
int minelement()
{
	return s2.top();
}
int main()
{
	push(5);
	push(11);
	push(3);

	cout<<top()<<endl;
	cout<<minelement()<<endl;

	push(1);
	push(13);

	//pop();
	pop();
	cout<<minelement()<<endl;
	return 0;
}