#include<bits/stdc++.h>
using namespace std;

bool Possible(int a[],int n)
{
	int maximum=a[0];
	for(int i=0;i<=maximum;i++)
	{
		if(maximum>=n-1)
			return true;
		maximum = max(i+a[i],maximum);
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	if(Possible(a,n))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	return 0;
}