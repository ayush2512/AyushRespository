#include<bits/stdc++.h>
using namespace std;

bool possible(int a[],int n,int sum)
{
	int dp[sum+1][n+1];
	for(int i=0;i<n;i++)
		dp[0][i]=true;
	for(int i=1;i<=sum;i++)
		dp[i][0]=false;

	for(int s=1;s<=sum;s++)
	{
		for(int i=1;i<=n;i++)
		{
			dp[s][i] = dp[s][i-1];
			if(s>=a[i-1])
				dp[s][i] = dp[s][i] || dp[s-a[i-1]][i-1];
		}
	}
	return dp[sum][n];
}
int main()
{
	int n,sum;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>sum;
	if(possible(a,n,sum))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	return 0;
}