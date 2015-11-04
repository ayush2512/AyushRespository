#include<iostream>
#include<climits>
using namespace std;
 
#define INF INT_MAX
#define N 4
 
int minCost(int cost[][N])
{
    int dp[N];
    for(int i=0;i<N;i++)
      dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<N;i++)
    {
      for(int j=i+1;j<N;j++)
      {
        if(dp[j] > dp[i]+cost[i][j])
          dp[j] = dp[i]+cost[i][j];
      }
    }
    return dp[N-1];
}
 
// Driver program to test above function
int main()
{
    int cost[N][N] = { {0, 15, 80, 90},
                      {INF, 0, 40, 50},
                      {INF, INF, 0, 70},
                      {INF, INF, INF, 0}
                    };
    cout << "The Minimum cost to reach station "<< N << " is " << minCost(cost)<<endl;
    return 0;
}