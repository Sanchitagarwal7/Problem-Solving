#include<bits/stdc++.h>
using namespace std;

/*Memoization*/
int findWays(int amount, vector<int>& coins, int index, vector<vector<int>> &dp)
{
    //base case
    if(index == 0)
    {
        if(amount%coins[index] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(dp[index][amount]!=-1) return dp[index][amount];

    int not_take = findWays(amount, coins, index-1, dp);
    int take = 0;

    if(coins[index]<=amount)
    {
        take = findWays(amount-coins[index], coins, index, dp);
    }

    return dp[index][amount] = not_take + take;
}
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    int index = n-1;

    vector<vector<int>> dp(n, vector<int>(amount+1, -1));

    return findWays(amount, coins, index, dp);
}


/*Tabulation*/
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    int index = n-1;

    vector<vector<int>> dp(n, vector<int>(amount+1, 0));

    for(int i = 0; i<=amount; i++)
    {
        if(i%coins[0] == 0)
        {
            dp[0][i] = 1;
        }
        else
        {
            dp[0][i] = 0;
        }
    }

    for(int ind = 1; ind<n; ind++)
    {
        for(int target = 0; target<=amount; target++)
        {
            int not_take = dp[ind-1][target];
            int take = 0;

            if(coins[ind]<=target)
            {
                take = dp[ind][target-coins[ind]];
            }

            dp[ind][target] = not_take + take;
        }
    }

    return dp[n-1][amount];
}


/*Space Optimisation*/
int change(int amount, vector<int>& coins) {
    int n = coins.size();

    int index = n-1;

    vector<int> prev(amount+1, 0);
    vector<int> curr(amount+1, 0);

    for(int i = 0; i<=amount; i++)
    {
        if(i%coins[0] == 0)
        {
            prev[i] = 1;
        }
        else
        {
            prev[i] = 0;
        }
    }

    for(int ind = 1; ind<n; ind++)
    {
        for(int target = 0; target<=amount; target++)
        {
            int not_take = prev[target];
            int take = 0;

            if(coins[ind]<=target)
            {
                take = curr[target-coins[ind]];
            }

            curr[target] = not_take + take;
        }
        prev = curr;
    }

    return prev[amount];
}
int main(){
    return 0;
}