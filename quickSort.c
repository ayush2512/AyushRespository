#include<stdio.h>
void swap(int *e1,int *e2)
{
	int temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}
int Partition(int *a,int start,int end)
{
	int pivot,pIndex,i;
	pivot = a[end];
	pIndex = start;
	for(i=start;i<end;i++)
	{
		if(a[i]<=pivot)
		{
			swap(&a[i],&a[pIndex]);
			pIndex++;
		}
	}
	swap(&a[pIndex],&a[end]);
	return pIndex;
}
void QuickSort(int *a,int start,int end)
{
	if(start>=end)
		return;
	int pIndex = Partition(a,start,end);
	QuickSort(a,start,pIndex-1);
	QuickSort(a,pIndex+1,end);
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	QuickSort(a,0,n-1);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}