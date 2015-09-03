#include<stdio.h>
void Merge(int left[],int nL,int right[],int nR,int a[])
{
	int i=0,j=0,k=0;
	while(i<nL && j<nR)
	{
		if(left[i]<right[j])
		{
			a[k]=left[i];
			k++;
			i++;
		}
		else
		{
			a[k]=right[j];
			k++;
			j++;
		}
	}
	while(i<nL)
	{
		a[k]=left[i];
		k++;
		i++;
	}
	while(j<nR)
	{
		a[k]=right[j];
		k++;
		j++;
	}
}

void MergeSort(int a[], int size)
{
	int i,mid;
	if(size<2)
		return;
	mid = size/2;
	int left[mid], right[size-mid];
	for(i=0;i<mid;i++)
		left[i]=a[i];
	for(i=mid;i<size;i++)
		right[i-mid]=a[i];
	MergeSort(left,mid);
	MergeSort(right,size-mid);
	Merge(left,mid,right,size-mid,a);
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	MergeSort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}