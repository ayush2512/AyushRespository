#include<bits/stdc++.h>
using namespace std;

int power(int mid,int root)
{
	int ans=1;
	while(root)
	{
		if(root%2)
			ans = ans*mid;
		mid = mid*mid;
		root=root/2;
	}
	//cout<<"ans = "<<ans<<endl;
	return ans;
}
int nRoot(int num,int root)
{
	int ans;
	int low = 1,high=num;
	while(low<=high)
	{
		int mid = (low+high)/2;
		//cout<<"mid = "<<mid<<endl;
		int mul = power(mid,root);
		if(mul <= num)
		{
			ans = mid;
			low=mid+1;
		}
		else if(mul>num)
			high=mid-1;
	}
	return ans;
}
int main()
{
	int num,root;
	cin>>num>>root;
	cout<<nRoot(num,root)<<endl;
	return 0;
}