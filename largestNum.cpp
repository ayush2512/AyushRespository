#include<bits/stdc++.h>
using namespace std;

bool cmpNum(string a,string b)
{
	return a+b>b+a;
}
string largestNumber(vector<int> &num)
{
	string res;
	vector<string> temp;
	for(int i=0;i<num.size();i++)
	{
		stringstream ss;
		ss << num[i];
		string str = ss.str();
		temp.push_back(str);
	}
	sort(temp.begin(),temp.end(),cmpNum);
	for(int i=0;i<temp.size();i++)
		res+=temp[i];
	int pos=0;
	while(res[pos]=='0' && pos<res.size())
		pos++;
	return res.substr(pos);
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
	cout<<largestNumber(a)<<endl;
	return 0;
}