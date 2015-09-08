#include<bits/stdc++.h>
using namespace std;

int MIS(int A[],int n)
{
	int dp[n];
	for(int i=0;i<n;i++)
		dp[i]=A[i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(A[i]>A[j] && dp[i] < dp[j]+A[i])
				dp[i] = dp[j] + A[i];
		}
	}
	int max = dp[0];
	for(int i=1;i<n;i++)
	{
		if(max<dp[i])
			max=dp[i];
	}
	return max;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Maximum length of LIS = "<<MIS(a,n)<<endl;
	return 0;
}