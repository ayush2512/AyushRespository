#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

int MinCost(int cost[R][C])
{
	int mincost = INT_MAX;
	queue<pair<int,pair<int,int> > > q;
	q.push(make_pair(cost[0][0],make_pair(0,0)));
	//map<pair<int,int>,bool> visited;
	//visited[make_pair(0,0)] = true;
	while(!q.empty())
	{
		int curCost = q.front().first;
		int i = q.front().second.first;
		int j = q.front().second.second;
		q.pop();

		if(i==R-1 && j==C-1)
		{
			if(mincost>curCost)
				mincost=curCost;
		}
		if(i+1<R)
		{
			q.push(make_pair(curCost+cost[i+1][j],make_pair(i+1,j)));
		}
		if(j+1<C)
		{
			q.push(make_pair(curCost+cost[i][j+1],make_pair(i,j+1)));
		}
		if(i+1<R)
		{
			q.push(make_pair(curCost+cost[i+1][j+1],make_pair(i+1,j+1)));
		}
		if(i+1<R)
		{
			q.push(make_pair(curCost+cost[i+1][j-1],make_pair(i+1,j-1)));
		}
	}
	return mincost;
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