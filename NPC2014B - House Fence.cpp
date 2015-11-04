#include<bits/stdc++.h>
using namespace std;

int find(int a[],int low,int high)
{
	int minimum=a[low],minIndex=low;
	for(int i=low+1;i<=high;i++)
	{
		if(a[i]<minimum)
		{
			minimum=a[i];
			minIndex=i;
		}
	}
	return minIndex;
}
int Fence(int a[],int low,int high)
{
	int res = high-low+1;
	if(low==high && a[high]!=0)
		return 1;
	else if((low>high) || (low==high && a[high]==0))
		return 0;
	int count=0;
	int minIndex = find(a,low,high);
	int temp = a[minIndex];
	count += a[minIndex];
	//cout<<"low = "<<low<<" "<<"high = "<<high<<" "<<"res = "<<res<<" "<<"minIndex = "<<minIndex<<" "<<"count = "<<count<<" "<<endl;
	for(int i=low;i<=high;i++)
		a[i]-=temp;
	cout<<endl;
	res = min(res,count+Fence(a,low,minIndex-1)+Fence(a,minIndex+1,high));

	return res;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int minimum = Fence(a,0,n-1);
	cout<<minimum<<endl;
	return 0;
}