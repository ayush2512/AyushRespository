#include<stdio.h>
int max(int x, int y)
{
    return x > y? x : y;
}
 
int min(int x, int y)
{
    return x < y? x : y;
}
int maximumGap(const int* A, int n1)
{
	int i,j,lmin[n1],rmax[n1],maxdiff;
	lmin[0]=A[0];
	for(i=1;i<n1;i++)
		lmin[i] = min(A[i],lmin[i-1]);

	rmax[n1-1]= A[n1-1];
	for(j=n1-2;j>=0;j--)
		rmax[j] = max(A[i],rmax[j+1]);

	i=0,j=0,maxdiff=0;
	while(i<n1 && j<n1)
	{
		printf("a\n");
		if(lmin[i] < rmax[j])
		{
			maxdiff = max(maxdiff, j-i);
			j++;
		}
		else
			i++;
	}
	return maxdiff;
}
int main()
{
	int i,n,gap;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	gap =maximumGap(a,n);
	printf("%d\n",gap);
	return 0;
}