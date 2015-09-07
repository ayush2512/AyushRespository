#include<bits/stdc++.h>
using namespace std;

int lcs(char x[],int m,char y[],int n)
{
	int dp[m+1][n+1];
	
	for(int i=0;i<=m;i++)
		dp[i][0]=0;
	for(int j=0;j<=n;j++)
		dp[0][j]=0;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[m][n];
}
int main()
{
	char X[] = "AGGTAB";
  	char Y[] = "GXTXAYB";
  
  	int m = strlen(X);
  	int n = strlen(Y);
  
  	cout<<"Length of LCS is "<<lcs( X,m,Y,n )<<endl;
  	return 0;
}