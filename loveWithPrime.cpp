//Goldbach conjecture
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int test,n;
	cin>>test;
	while(test--)
	{
		cin>>n;
		if(n%2==0 && n<=100000)
		{
			if(n!=2)
				cout<<"Deepa"<<endl;
			else
				cout<<"Arjit"<<endl;
		}
	}
	return 0;
}