#include<bits/stdc++.h>
using namespace std;

int LongestChain(vector<string> V)
{
	int dp[1000];
	int ans;
	vector<pair<int,string> > list;
	for(int i=0;i<V.size();i++)
		list.push_back(make_pair(V[i].size(),V[i]));
	sort(list.begin(),list.end());
	map<string,int > m;
	map<string,int > :: iterator it;
	m[list[0].second]=0;
	dp[0]=1;
	ans = dp[0];
	for(int i=1;i<list.size();i++)
	{
		dp[i]=1;
		string temp = list[i].second;
		//cout<<list[0].second<<endl;
		for(int j=0;j<temp.size();j++)
		{
			string temp1 = temp;
			temp1.erase(temp1.begin()+j);
			//cout<<temp1<<endl;

			it = m.find(temp1);
			if(it!=m.end()){
				dp[i] = max(dp[i],dp[it->second]+1);
				//cout<<"helo"<<endl;
			}
		}
		ans = max(ans,dp[i]);
		m[temp]=i;
	}
	return ans;
}
int main()
{
	int N;
	cin >> N;
	vector<string> V(N);
	for (int i=0;i<N;i++)
		cin >> V[i];

	cout << LongestChain(V) << endl;
	return 0;
}