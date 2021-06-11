//OM NAMO NARAYANA
#include<bits/stdc++.h>
using namespace std;

int maxNutrient(vector<int> cost, vector<int> nutrients, vector<int> min_nutrients, vector<int> max_nutrients, int m)
{
    int n=cost.size();
    int res=0, val=0;
    for(int i=0; i<n; i++)
    {
        res += min_nutrients[i]*nutrients[i];
        val -= cost[i]*min_nutrients[i];
    }
    if(val < 0)return 0;
    int dp[val+1][n];
    memset(dp, 0, sizeof(dp));
    for(int i=0; i<=val; i++)
    {
        for(int j=0; j<n; j++)
        {
            dp[i][j]=max(dp[i][j], )
        }
    }
}