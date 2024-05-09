#include<bits/stdc++.h>
using namespace std;

/*MEMOIZATION*/
int minCoins(vector<int>& coins, int amount, int index, vector<vector<int>> &dp)
{
    //base case
    if(amount == 0) return 0;
    if(index == 0)
    {
        if(amount%coins[index] == 0)
        {
            return amount/coins[index];
        }
        else
        {
            return 1e8;
        }
    }
    if(dp[index][amount]!=-1) return dp[index][amount];

    //do not current coin and go to next coins
    int not_take = minCoins(coins, amount, index-1, dp);

    //take the current coin
    int take = 1e8;
    if(coins[index]<=amount)
    {
        //we are not decrementing index becoz we have infinite supply coins
        take = 1 + minCoins(coins, amount-coins[index], index, dp);
    }

    return dp[index][amount] = min(not_take, take);

}
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    int index = n-1;

    vector<vector<int>> dp(n, vector<int>(amount+1, -1));

    int minNumberOfCoins = minCoins(coins, amount, index, dp);

    if(minNumberOfCoins>=1e8)
    {
        return -1;
    }
    return minNumberOfCoins;
}

/*Tabulation*/
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    int index = n-1;

    vector<vector<int>> dp(n, vector<int>(amount+1, 0));

    //for amount equals 0 we cant add any coins
    for(int i = 0; i<n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i = 1; i<=amount; i++)
    {
        if(i % coins[0] == 0)
        {
            dp[0][i] = i/coins[0];
        }
        else
        {
            dp[0][i] = 1e8;
        }
    }
    for(int ind = 1; ind<n; ind++)
    {
        for(int target = 1; target<=amount; target++)
        {
            //do not current coin and go to next coins
            int not_take = dp[ind-1][target];

            //take the current coin
            int take = 1e8;
            if(coins[ind]<=target)
            {
                //we are not decrementing index becoz we have infinite supply coins
                take = 1 + dp[ind][target-coins[ind]];
            }
            dp[ind][target] = min(not_take, take);
        }
    }

    if(dp[n-1][amount]>=1e8)
    {
        return -1;
    }
    return dp[n-1][amount];
}

/*Space Optimisation*/
int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();

    int index = n-1;

    vector<int> prev(amount+1, 0);
    vector<int> temp(amount+1, 0);

    //for amount equals 0 we cant add any coins
    for(int i = 0; i<n; i++)
    {
        prev[0] = 0;
    }

    for(int i = 1; i<=amount; i++)
    {
        if(i % coins[0] == 0)
        {
            prev[i] = i/coins[0];
        }
        else
        {
            prev[i] = 1e8;
        }
    }

    for(int ind = 1; ind<n; ind++)
    {
        for(int target = 1; target<=amount; target++)
        {
            //do not current coin and go to next coins
            int not_take = prev[target];

            //take the current coin
            int take = 1e8;
            if(coins[ind]<=target)
            {
                //we are not decrementing index becoz we have infinite supply coins
                take = 1 + temp[target-coins[ind]];
            }
            temp[target] = min(not_take, take);
        }
        prev = temp;
    }

    if(prev[amount]>=1e8)
    {
        return -1;
    }
    return prev[amount];
}

int main(){
    return 0;
}