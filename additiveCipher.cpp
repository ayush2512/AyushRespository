#include<bits/stdc++.h>
using namespace std;

int main()
{
	char p[100],c[100];
	int key;
	cout<<"Enter the plaintext"<<endl;
	cin>>p;
	cout<<"Enter the key"<<endl;
	cin>>key;
	int i=0;
	while(p[i]!='\0')
	{
		c[i] = (p[i]-97+key)%26+65;
		//cout<<c[i]<<" ";
		i++;
	}
	//cout<<endl;
	c[i]='\0';
	cout<<"The decrypted message is = ";
	cout<<c<<endl;
	return 0;
}