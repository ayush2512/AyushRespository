#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3


int lcc(char mat[R][C],char s)
{
	queue<pair<char,pair<int,pair<int,int> > > > q;
	map<pair<int,int>,bool> visited;

	int x,y,count,flag=0,maxcount=0;
	for(x=0;x<R;x++)
	{
		for(y=0;y<C;y++)
		{
			if(mat[x][y]==s)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
	}
	if(flag==0)
		return 0;
	q.push(make_pair(s,make_pair(1,make_pair(x,y))));
	visited[make_pair(x,y)] = true;

	while(!q.empty())
	{
		char temp = q.front().first;
		count = q.front().second.first;
		int i = q.front().second.second.first;
		int j = q.front().second.second.second;
		q.pop();

		if(maxcount<count)
			maxcount = count;

		if(i-1>=0 && j-1>=0 && mat[i-1][j-1]-temp==1 && visited[make_pair(i-1,j-1)]==false)
		{
			q.push(make_pair(mat[i-1][j-1],make_pair(count+1,make_pair(i-1,j-1))));
			visited[make_pair(i-1,j-1)]=true;
		}
		else if(i-1>=0 && mat[i-1][j]-temp==1 && visited[make_pair(i-1,j)]==false)
		{
			q.push(make_pair(mat[i-1][j],make_pair(count+1,make_pair(i-1,j))));
			visited[make_pair(i-1,j)]=true;
		}
		else if(i-1>=0 && j+1<=C && mat[i-1][j+1]-temp==1 && visited[make_pair(i-1,j+1)]==false)
		{
			q.push(make_pair(mat[i-1][j+1],make_pair(count+1,make_pair(i-1,j+1))));
			visited[make_pair(i-1,j+1)]=true;
		}
		else if(j-1>=0 && mat[i][j-1]-temp==1 && visited[make_pair(i,j-1)]==false)
		{
			q.push(make_pair(mat[i][j-1],make_pair(count+1,make_pair(i,j-1))));
			visited[make_pair(i,j-1)]=true;
		}
		if(j+1<=C && mat[i][j+1]-temp==1 && visited[make_pair(i,j+1)]==false)
		{
			q.push(make_pair(mat[i][j+1],make_pair(count+1,make_pair(i,j+1))));
			visited[make_pair(i,j+1)]=true;
		}
		else if(i+1<=R && j-1>=0 && mat[i+1][j-1]-temp==1 && visited[make_pair(i+1,j-1)]==false)
		{
			q.push(make_pair(mat[i+1][j-1],make_pair(count+1,make_pair(i+1,j-1))));
			visited[make_pair(i+1,j-1)]=true;
		}
		if(i+1<=R && mat[i+1][j]-temp==1 && visited[make_pair(i+1,j)]==false)
		{
			q.push(make_pair(mat[i+1][j],make_pair(count+1,make_pair(i+1,j))));
			visited[make_pair(i+1,j)]=true;
		}
		if(i+1<=R && j+1<=C && mat[i+1][j+1]-temp==1 && visited[make_pair(i+1,j+1)]==false)
		{
			q.push(make_pair(mat[i+1][j+1],make_pair(count+1,make_pair(i+1,j+1))));
			visited[make_pair(i+1,j+1)]=true;
		}
	}
	return maxcount;
}
int main()
{
	char mat[3][3];
	for(int i=0;i<R;i++)
	{
		for(int j=0;j<C;j++)
			cin>>mat[i][j];
	}
	char s;
	cin>>s;
	cout<<"Length of longest Consective characters starting from "<<s<< " = "<<lcc(mat,s)<<endl;
	return 0;
}