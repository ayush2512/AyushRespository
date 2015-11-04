#include<bits/stdc++.h>
using namespace std;

int ways(int n)
{
	if(n==1)
		return 4;
	int countb=1,counts=1,prevb,prevs;
	for(int i=2;i<=n;i++)
	{
		prevb=countb;
		prevs=counts;

		counts = prevb + prevs;
		countb = prevs;
	}
	return (countb + counts)*(countb + counts);
}
int main()
{
	int n;
	cin>>n;
	cout<<"Number of ways to construct building = "<<ways(n)<<endl;
	return 0;
}