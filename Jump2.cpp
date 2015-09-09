#include<bits/stdc++.h>
using namespace std;

int minJump(int a[],int n)
{
	int dp[n];
	int j=1;
	dp[0]=0;
	for(int i=0;i<n;i++)
	{
		int num = dp[i];
		if(i>=j)
			return -1;
		while(j<=i+a[i] && j<n)
			dp[j++] = num+1;
	}
	return dp[n-1];
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<"Minimum jumps = "<<minJump(a,n)<<endl;
	return 0;
}