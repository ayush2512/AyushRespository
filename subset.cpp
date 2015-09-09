#include<bits/stdc++.h>
using namespace std;

void generateSubset(vector<int> &A, vector<vector<int> > &res, vector<int> &temp, int k,map<vector<int>,bool> &m)
{
	if(k>A.size())
		return;
	if(k<=A.size())
	{
		if(m[temp]==false)
		{
			res.push_back(temp);
			m[temp]=true;
		}
	}
	for(int i=k;i<A.size();i++)
	{
		if(i>k && A[i]==A[i-1])
			continue;
		temp.push_back(A[i]);
		generateSubset(A,res,temp,i+1,m);
		temp.pop_back();
	}
}
void subset(vector<int> &A)
{
	if(A.size()==0)
		return;
	sort(A.begin(),A.end());
	vector<vector<int> > res;
	vector<int> temp;
	map<vector<int>,bool> m;
	
	generateSubset(A,res,temp,0,m);
	sort(res.begin(),res.end());

	for(int i=0;i<res.size();i++)
	{
		for(int j=0;j<res[i].size();j++)
			cout<<res[i][j]<<" ";
		cout<<endl;
	}
}
int main()
{
	vector<int> A;
	int temp;
	for(int i=0;i<3;i++)
	{
		cin>>temp;
		A.push_back(temp);
	}
	subset(A);
	return 0;
}