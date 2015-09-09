#include<bits/stdc++.h>
using namespace std;

void maxSubsequence(int a[],int n)
{
	vector<int> temp,res;
	sort(a,a+n);
	temp.push_back(a[0]);
	for(int i=1;i<n;i++)
	{
		if(a[i]-a[i-1]==1)
		{
			temp.push_back(a[i]);
			if(i==n-1)
			{
				res = temp;
				temp.clear();
			}
		}
		else
		{
			if(temp.size()>1 && temp.size()>res.size())
			{
				res.clear();
				res = temp;
			}
			temp.clear();
			temp.push_back(a[i]);
		}
	}
	for(int i=0;i<res.size();i++)
		cout<<res[i]<<" ";
	cout<<endl;
}
int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	maxSubsequence(a,n);
	return 0;
}