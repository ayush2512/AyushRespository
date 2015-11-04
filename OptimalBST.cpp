#include<bits/stdc++.h>
using namespace std;

int sum(int freq[],int l,int r)
{
	int s=0;
	for(int i=l;i<=r;i++)
		s += freq[i];
	return s;
}
int cost(int keys[],int freq[],int n)
{
	int cost[n][n];
	for(int i=0;i<n;i++)
		cost[i][i] = freq[i];
	for(int l=2;l<=n;l++)
	{
		for(int i=0;i<=n-l+1;i++)
		{
			int j = i+l-1;
			cost[i][j] = INT_MAX;
			for(int r=i;r<=j;r++)
			{
				int c = ((r > i)? cost[i][r-1]:0) + ((r < j)? cost[r+1][j]:0) + sum(freq, i, j);
				if(c<cost[i][j])
					cost[i][j] = c;
			}
		}
	}
	return cost[0][n-1];
}
int main()
{
	int n;
	cin>>n;
	int keys[n],freq[n];
	for(int i=0;i<n;i++)
		cin>>keys[i];
	for(int i=0;i<n;i++)
		cin>>freq[i];
	cout<<"Cost of optimal BST  = "<<cost(keys,freq,n)<<endl;
	return 0;
}