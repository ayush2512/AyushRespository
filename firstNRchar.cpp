#include<bits/stdc++.h>
using namespace std;

struct minIndex
{
	int count;
	int index;
};
int main()
{
	char s[10000];
	cin>>s;

	struct minIndex *find = (struct minIndex *)calloc(sizeof(minIndex), 256);

	int i=0,result=INT_MAX;
	while(s[i]!='\0')
	{
		find[*(s+i)].count++;
		if(find[*(s+i)].count==1)
			find[*(s+i)].index=i;
		i++;
	}
	for(int i=0;i<256;i++)
	{
		if(find[i].count==1 && result>find[i].index)
			result = find[i].index;
	}
	cout<<s[result]<<endl;
	return 0;
}