#include<bits/stdc++.h>
using namespace std;

int Mways(int coin[],int m,int n)
{
	int dp[n+1][m];
	memset(dp,0,sizeof(dp));
	for(int j=0;j<m;j++)
		dp[0][j]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		{
			int x = (i-coin[j] >= 0)?dp[i-coin[j]][j] : 0;		// Count of solutions including coin[j]
			int y = (j>=1)?dp[i][j-1]:0;					// Count of solutions excluding coin[j]

			dp[i][j] = x+y;
		}
	}
	return dp[n][m-1];
}
int main()
{
	int m,n;
	cin>>m;
	int coin[m];
	for(int i=0;i<m;i++)
		cin>>coin[i];
	cin>>n;
	cout<<"Maximum ways = "<<Mways(coin,m,n)<<endl;
	return 0;
}