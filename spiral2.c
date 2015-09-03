#include<stdio.h>
int main()
{
	int i,j,n,dir,T,B,L,R;
	scanf("%d",&n);
	int a[n][n];
	T=0, B=n-1, L=0, R=n-1,dir=0;
	int val = 1;
	while(val<=n*n && T<=B && L<=R)
	{
		if(dir==0)
		{
			for(i=L;i<=R;i++)
			{
				a[T][i]=val;
				val++;
			}
			dir=1;
			T++;
			//printf("val = %d, T = %d, B = %d, L = %d, R = %d\n",val,T,B,L,R);
		}
		else if(dir==1)
		{
			for(i=T;i<=B;i++)
			{
				a[i][R]=val;
				val++;
			}
			dir=2;
			R--;
		}
		else if(dir == 2)
		{
			for(i=R;i>=L;i--)
			{
				a[B][i]=val;
				val++;
			}
			B--;
			dir=3;
		}
		else if(dir==3)
		{
			for(i=B;i>=T;i--)
			{
				a[i][L]=val;
				val++;
			}
			L++;
			dir=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}