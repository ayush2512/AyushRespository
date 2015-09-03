#include<bits/stdc++.h>
using namespace std;

int cutRod(int a[],int n)
{
	int dp[n+1];
	int temp;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		temp = INT_MIN;
		for(int j=0;j<i;j++)
			temp = max(temp,a[j]+dp[i-j-1]);
		dp[i] = temp;
	}
	return dp[n];
}
int main()
{
	int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Maximum Obtainable Value is %d\n", cutRod(arr, size));
    return 0;
}