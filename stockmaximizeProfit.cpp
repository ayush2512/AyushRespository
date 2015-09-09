#include<bits/stdc++.h>
using namespace std;

int maximize(int a[],int n)
{
	int min=a[0],maxdiff=INT_MIN;
	for(int i=1;i<n;i++)
	{
		if(a[i]<min)
			min=a[i];
		int diff = a[i]-min;
		if(diff>maxdiff)
			maxdiff=diff;
	}
	return maxdiff;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Maximum Profit = "<<maximize(a,n)<<endl;
	return 0;
}