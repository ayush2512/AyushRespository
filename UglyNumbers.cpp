#include<bits/stdc++.h>
using namespace std;

int findUgly(int ugly[],int n)
{
	ugly[0]=1;
	int i2=1,i3=1,i5=1;

	for(int i=1;i<=n;i++)
	{
		int temp = min(i2*2,min(i3*3,i5*5));
		if(temp == i2*2)
		{
			ugly[i]=i2*2;
			i2++;
		}
		if(temp == i3*3)
		{
			ugly[i]=i3*3;
			i3++;
		}
		if(temp == i5*5)
		{
			ugly[i]=i5*5;
			i5++;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int ugly[n];
	findUgly(ugly,n);

	for(int i=0;i<n;i++)
		cout<<ugly[i]<<" ";
	cout<<endl;

	return 0;
}