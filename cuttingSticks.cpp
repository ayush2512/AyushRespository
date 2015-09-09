#include<bits/stdc++.h>
using namespace std;

int minCost(int len,int numCuts)
{
	int i,j,k,flag,min,cost;
	int endpts[numCuts+2];
	endpts[0]=0;
	for(int i=1;i<=numCuts;i++)
		cin>>endpts[i];
	endpts[numCuts+1]=len;
	
	int dp[numCuts+2][numCuts+2];
	for(i=0;i<numCuts+2;i++)	//Initialization - minimal cost of cutting a segment with no cutting point in it is 0
		dp[i][i+1]=0;
	for(int gap=2;gap<numCuts+2;gap++)
	{
		for(i=0;i+gap<numCuts+2;i++)
		{
			j = i+gap;
			int len = endpts[j]-endpts[i];
			min=-1;
			flag=1;
			for(int k=i+1;k<j;k++)
			{
				cost = dp[i][k] + dp[k][j];
				if(flag)
				{
					min = cost;
					flag=0;
				}
				else
					min=cost;
			}
			dp[i][j] = len+cost;
		}
	}
	return dp[0][numCuts+1];
}
int main()
{
	int len,numCuts;
	cin>>len>>numCuts;
	cout<<minCost(len,numCuts)<<endl;
	return 0;
}