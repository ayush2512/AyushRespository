#include<bits/stdc++.h>
using namespace std;

#define Insert 1
#define Delete 1
#define Replace 1

int editDis(char x[],int m,char y[],int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
		dp[i][0]=i;
	for(int j=0;j<=n;j++)
		dp[0][j]=j;

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j] = min(dp[i-1][j]+Delete,dp[i][j-1]+Insert);
			if(x[i-1]==y[j-1])
				dp[i][j] = min(dp[i-1][j-1],dp[i][j]);
			else
				dp[i][j] = min(dp[i-1][j-1]+Insert,dp[i][j]);
		}
	}
	return dp[m][n];
}
int main()
{
	char X[] = "SUNDAY";
  	char Y[] = "SATURDAY";
  
  	int m = strlen(X);
  	int n = strlen(Y);
  
  	cout<<"Minimum steps required = "<<editDis( X,m,Y,n )<<endl;
  	return 0;
}