#include<bits/stdc++.h>
using namespace std;

void preprocess(int table[][2],int k)
{
	for(int state=0;state<k;state++)
	{
		int t0,t1;
		t0 = state<<1;
		table[state][0]=(t0<k)?t0:t0-k;
		t1 = (state<<1) + 1;
		table[state][1] = (t1<k)?t1:t1-k;
	}
}
void check(int num,int *state,int table[][2])
{
	if(num!=0)
	{
		check(num>>1,state,table);
		*state = table[(*state)][num&1];
	}
}
int isdivisible(int num,int k)
{
	int table[k][2];
	preprocess(table,k);

	int state=0;
	check(num,&state,table);
	return state;
}
int main()
{
	int num,k;
	cin>>num>>k;
	int remainder = isdivisible(num,k);
	if(remainder==0)
		cout<<"Divisible"<<endl;
	else
		cout<<"Remainder = "<<remainder<<endl;
	return 0;
}