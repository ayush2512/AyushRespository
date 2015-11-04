#include<bits/stdc++.h>
using namespace std;

struct comp
{
	bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
        return left.second < right.second;
    }
};
int main()
{
	int n,count=0,temp1,temp2;
	cin>>n;
	vector<pair<int,int> > job;
	for(int i=0;i<n;i++)
	{
		cin>>temp1>>temp2;
		job.push_back(make_pair(temp1,temp2));
	}
	sort(job.begin(),job.end(),comp());
	int i=0;
	cout<<i<<" ";
	count++;
	for(int j=1;j<n;j++)
	{
		if(job[j].first >= job[i].second)
		{
			i=j;
			cout<<i<<" ";
			count++;
		}
	}
	cout<<endl;
	cout<<"Number of jobs = "<<count<<endl;
	return 0;
}