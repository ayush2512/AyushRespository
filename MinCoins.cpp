#include<bits/stdc++.h>
using namespace std;

int minCoin(int c[],int n,int sum)
{
	int dp[sum+1];
	dp[0]=0;
	for(int i=1;i<=sum;i++)
	{
		int res = INT_MAX;
		for(int j=0;j<n;j++)
		{
			if(i>=c[j])
				res = min(res,1+dp[i-c[j]]);
		}
		dp[i] = res;
	}
	return dp[sum];
}
int main()
{
	int n,sum;
	cin>>n;
	int coins[n];
	for(int i=0;i<n;i++)
		cin>>coins[i];
	cin>>sum;
	cout<<"Minimum number of coins = "<<minCoin(coins,n,sum)<<endl;
	return 0;
}