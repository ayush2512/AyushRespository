#include<bits/stdc++.h>
using namespace std;

struct compare
{
    bool operator()(int lhs, int rhs) 
    {
        return lhs>rhs;
    }
};
int main()
{
	long long int n,k,max;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>k;
	map<int,int,compare> m;
	map<int,int> :: iterator it;

	for(int i=0;i<k;i++)
		m[a[i]]++;
	for(int i=0;i<n-k;i++)
	{
		it=m.begin();
		max = it->first;
		cout<<max<<" ";
		
		m[a[i]]--;
		if(m[a[i]]==0)
		{
			it = m.find(a[i]);
			m.erase(it);
		}
		
		m[a[i+k]]++;
	}
	it=m.begin();
	max = it->first;
	cout<<max<<endl;
	return 0;
}