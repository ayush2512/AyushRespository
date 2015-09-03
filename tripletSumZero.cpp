#include<bits/stdc++.h>
using namespace std;

int tripletZero(int A[],int n)
{
	sort(A,A+n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		j=i+1,k=n-1;
		while(j<k)
		{
			if(A[i]+A[j]+A[k]==0)
			{
				printf("%d %d %d\n",A[i],A[j],A[k]);
				break;
			}
			else if(A[i]+A[j]+A[k]>0)
				k--;
			else
				j++;
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	tripletZero(a,n);
	return 0;
}