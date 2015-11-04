#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) 
{
    int water = 0;
    int n = height.size();
    if(n==0)
        return 0;
    int left[n],right[n];
    left[0] = height[0],right[n-1] = height[n-1];
        
    for(int i=1;i<n;i++)
        left[i] = max(left[i-1],height[i]);
    for(int i=n-2;i>=0;i--)
        right[i] = max(right[i+1],height[i]);
            
    for(int i=0;i<n;i++)
        water+=max(min(left[i],right[i])-height[i],0);
    return water;
}
int main()
{
    int n,temp;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        v.push_back(temp);
    }
    cout<<trap(v)<<endl;
    return 0;
}