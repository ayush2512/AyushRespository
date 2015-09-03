#include<bits/stdc++.h>
using namespace std;

int maximize(int a[],int n)
{
	int currmax = a[0];
	int resmax = a[0];
	for(int i=1;i<n;i++)
	{
		currmax = max(currmax+a[i],a[i]);
		resmax = max(currmax,resmax);
	}
	return resmax;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Maximum Contigous Sum = "<<maximize(a,n)<<endl;
	return 0;
}