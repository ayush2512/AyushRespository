#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test;
	cin>>test;
	while(test--)
	{
		int n;
		cin>>n;
		int a[n][n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cin>>a[i][j];
		}
		map<int,pair<int,int> > m;
		map<int,pair<int,int> > :: iterator it;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				m[a[i][j]] = make_pair(i,j);
		}
		it = m.begin();
		int x = it->second.first;
		int y = it->second.second;
		int count=0;
		it++;
		for(;it!=m.end();it++)
		{
			int i = it->second.first;
			int j = it->second.second;
			count += abs(x-i) + abs(y-j);
			x=i;
			y=j;
		}
		cout<<count<<endl;
	}
}