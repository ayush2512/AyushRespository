#include<bits/stdc++.h>
using namespace std;

#define m 3
#define n 3

int minSteps(int cost[m][n])
{
	int dp[m][n];
	memset(dp,0,sizeof(dp));

	dp[m-1][n-1] = 1 - min(0,cost[m-1][n-1]);

	for(int i=m-1;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			if(i+1<m && j+1<n)
			{
				int down = max(1,dp[i+1][j]-cost[i][j]);
				int right = max(1,dp[i][j+1]-cost[i][j]);
				dp[i][j] = min(down,right);
			}
			else if(i+1<m)
				dp[i][j] = max(1,dp[i+1][j]-cost[i][j]);
			else if(j+1<n)
				dp[i][j] = max(1,dp[i][j+1]-cost[i][j]);
		}
	}
	return dp[0][0];
}
int main()
{
	int cost[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
			cin>>cost[i][j];
	}
	cout<<"Minimum costs ="<<minSteps(cost)<<endl;
	return 0;
}