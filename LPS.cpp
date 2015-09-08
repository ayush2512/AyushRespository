//Longest Pallindromic Subsequence
#include<bits/stdc++.h>
using namespace std;

int lps(char x[])
{
	int n = strlen(x);
	int dp[n][n];

	for(int i=0;i<n;i++)
		dp[i][i]=1;
	for(int cl=2;cl<=n;cl++)
	{
		for(int i=0;i<n-cl+1;i++)
		{
			int j=i+cl-1;
			if(x[i]==x[j] && cl==2)
				dp[i][j]=2;
			else if(x[i]==x[j])
				dp[i][j] = 2 + dp[i+1][j-1];
			else
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
		}
	}
	return dp[0][n-1];
}
int main()
{
	char x[] = "GEEKS FOR GEEKS";
    cout<<"The lnegth of the LPS is "<<lps(x)<<endl;
    return 0;
}