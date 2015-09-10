#include<bits/stdc++.h>
using namespace std;

int profit(int p[],int n)
{
	int profit[n];
	memset(profit,0,sizeof(profit));
	int maxP = p[n-1];
	for(int i=n-2;i>=0;i--)
	{
		if(p[i]>maxP)
			maxP = p[i];
		profit[i] = max(profit[i+1],maxP-p[i]);
	}
	int minP = p[0];
	for(int i=1;i<n;i++)
	{
		if(p[i]<minP)
			minP = p[i];
		profit[i] = max(profit[i-1],profit[i]+p[i]-minP);
	}
	return profit[n-1];
}
int main()
{
	int n;
	cin>>n;
	int price[n];
	for(int i=0;i<n;i++)
		cin>>price[i];
	cout<<"Maximum profit = "<<profit(price,n)<<endl;
	return 0;
}