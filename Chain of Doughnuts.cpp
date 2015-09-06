#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n , m;
		cin >> n >> m;
		int a[m];
		for(int i = 0;i < m;i++)
			cin>>a[i];

		sort(a,a+m);

		int i = 0,j = m-1,ans = 0;
		while(i < j)
		{
			if(a[i])
			{
				a[i]--;
				j--;
				ans++;
			}
			else
			{
				i++;
			}
		}
		cout << ans << endl;
	}
	return 0;
}