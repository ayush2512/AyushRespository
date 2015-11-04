#include<bits/stdc++.h>
using namespace std;

int inverse(int key)
{
	int r1=26,r2=key,r,t1=0,t2=1,t,q;
	while(r2>0)
	{
		q=r1/r2;
		r = r1-q*r2;
		r1=r2;
		r2=r;
		t = t1-q*t2;
		t1=t2;
		t2=t;
	}
	while(t1<0)
		t1 = (t1+26)%26;
	return t1;
}
int main()
{
	char p[100],c[100];
	int mkey,akey,choice;
	cout<<"Encryption = 1 Decryption = 2"<<endl;
	cin>>choice;
	if(choice == 1)
	{
		cout<<"Enter the plaintext"<<endl;
		cin>>p;
		cout<<"Enter the additive key"<<endl;
		cin>>akey;
		cout<<"Enter the multiplicative key"<<endl;
		cin>>mkey;
		int i=0;
		while(p[i]!='\0')
		{
			c[i] = ((p[i]-97)*mkey+akey)%26+65;
			i++;
		}
		c[i]='\0';
		cout<<"The decrypted message is = ";
		cout<<c<<endl;
	}
	else if(choice==2)
	{
		cout<<"Enter the ciphertext"<<endl;
		cin>>c;
		cout<<"Enter the additive key"<<endl;
		cin>>akey;
		cout<<"Enter the multiplicative key"<<endl;
		cin>>mkey;
		int inv = inverse(mkey);
		int i=0;
		while(c[i]!='\0')
		{
			p[i] = (((c[i]-65-akey)*inv)+26)%26+97;
			i++;
		}
		p[i]='\0';
		cout<<"The message is = ";
		cout<<p<<endl;
	}
	return 0;
}