#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k;
	int inqueue=0;
	cin>>n;
	int h[n],alloted[n];
	memset(alloted,0,sizeof(alloted));
	for(int i=0;i<n;i++)
		cin>>h[i];
	cin>>k;
	priority_queue<pair<float,int> > mypq;
	for(int i=0;i<n;i++)
	{
		mypq.push(make_pair(h[i],i));
		alloted[i]++;
		inqueue++;
	}
	while(inqueue<k)
	{
		int index = mypq.top().second;
		alloted[index]++;
		mypq.pop();

		inqueue++;
		mypq.push(make_pair(h[index]/inqueue,index));
	}
	int max = INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(max<h[i]/alloted[i])
			max = h[i]/alloted[i];
	}
	cout<<max<<endl;
	return 0;
}