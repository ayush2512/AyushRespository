#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &num)
{
	int len = num.size();
	int j,i;
	for(j=len-2;j>=0;j--)
	{
		if(num[j]<num[j+1])
			break;
	}
	if(j==-1)
	{
		reverse(num.begin(),num.end());
		return;
	}
	for(i=len-1;i>j;i--)
	{
		if(num[i]>num[j])
			break;
	}
	swap(num[i],num[j]);
	reverse(num.begin()+j+1,num.end());
	return;
}
int main()
{
	int n;
	cin>>n;
	vector<int> a;
	int temp;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	nextPermutation(a);
	for(int i=0;i<a.size();i++)
		cout<<a[i];
	cout<<endl;
	return 0;
}