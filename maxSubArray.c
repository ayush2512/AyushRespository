#include<stdio.h>
int max(int s1,int s2)
{
	if(s1>s2)
		return s1;
	else
		return s2;
}
int MaxSubaraay(int a[],int size)
{
	int i,max1=a[0],max2=a[0];
	for(i=1;i<size;i++)
	{
		max1 = max(a[i],max1+a[i]);
		max2 = max(max2,max1);
	}
	return max2;
}
int main()
{
	int n, maxSum;
	printf("Enter the size\n");
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	maxSum = MaxSubaraay(a,n);
	printf("Maximum Sum = %d\n",maxSum);
	return 0;
}
