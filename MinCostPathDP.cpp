#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int MinCost(int cost[R][C])
{
	int dp[R][C];
	dp[0][0] = cost[0][0];
	for(int j=1;j<C;j++)
		dp[0][j] = dp[0][j-1] + cost[0][j];
	for(int i=1;i<R;i++)
		dp[i][0] = dp[i-1][0] + cost[i][0];

	for(int i=1;i<R;i++)
	{
		for(int j=1;j<C;j++)
			dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+cost[i][j];
	}
	return dp[R-1][C-1];
}
int main()
{
	int cost[R][C];
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cin>>cost[i][j];
	}
	cout<<"Minimum Cost = "<<MinCost(cost)<<endl;
	return 0;
}