#include<bits/stdc++.h>
using namespace std;

                                /*MEMOIZATION*/
int solve(int n, int &k, int target, int &mod, vector<vector<int>> &dp)
{
    //base case
    if(n < 1 && target != 0) return 0;
    if(n == 1 && target == 0) return 1;
    if(dp[n][target] != -1) return dp[n][target]; 

    int combs = 0;
    for(int face = 1; face <= k; face++)
    {
        if(face <= target)
        {
            combs = (combs+solve(n-1, k, target-face, mod, dp))%mod;
        }
    }

    return dp[n][target] = combs%mod;
}
int numRollsToTarget(int n, int k, int target) {
    int mod = 1e9+7;
    vector<vector<int>> dp(n+2, vector<int>(target+1, -1));
    return solve(n+1, k, target, mod, dp);
}


                                /*TABULATION*/
int numRollsToTarget(int n, int k, int target) {
    int mod = 1e9+7;
    vector<vector<int>> dp(n+2, vector<int>(target+1, 0));

    //base cases
    for(int i = 0; i<n+2; i++)
    {
        dp[i][0] = 0;
    }

    dp[1][0] = 1;

    for(int dice = 1; dice < n+2; dice++)
    {
        for(int tar = 1; tar < target+1; tar++)
        {
            int combs = 0;
            for(int face = 1; face <= k; face++)
            {
                if(face <= tar)
                {
                    combs = (combs + dp[dice-1][tar-face])%mod;
                }
            }

            dp[dice][tar] = combs%mod;
        }
    }
    
    return dp[n+1][target];
}

int main(){
    return 0;
}