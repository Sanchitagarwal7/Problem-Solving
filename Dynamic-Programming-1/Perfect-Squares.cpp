#include<bits/stdc++.h>
using namespace std;

                                    /*MEMOIZATION*/
int solve(vector<int> &nums, int index, int target, vector<vector<int>> &dp)
{
    //base case
    if(target == 0) return 0;
    if(index == nums.size()-1){
        if(target==nums[index])
        {
            return 1;
        }
    }
    if(dp[index][target]!=-1) return dp[index][target];

    int mini = 1e9;

    for(int i = index; i < nums.size(); i++)
    {
        if(nums[i] <= target)
        {
            int count = 1+solve(nums, i, target-nums[i], dp);
            mini = min(mini, count);
        }
    }
    return dp[index][target] = mini;
}

int numSquares(int n) {
    vector<int> perfectSquares;

    for(int num = 1; num <= sqrt(n); num++){
        int square = pow(num, 2);
        perfectSquares.push_back(square);
    }

    int index = 0;
    vector<vector<int>> dp(perfectSquares.size(), vector<int>(n+1, -1));

    return solve(perfectSquares, index, n, dp);
}


                                    /*TABULATION*/
int numSquares(int n) {
    vector<int> perfectSquares;

    for(int num = 1; num <= sqrt(n); num++){
        int square = pow(num, 2);
        perfectSquares.push_back(square);
    }

    int index = 0;
    vector<vector<int>> dp(perfectSquares.size(), vector<int>(n+1, 0));

    //base case
    for(int i = 0; i<perfectSquares.size(); i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i<perfectSquares.size(); i++)
    {
        if(perfectSquares[i] == n)
        {
            dp[i][n] = 1;
        }
    }

    for(int ind = perfectSquares.size()-1; ind>=0; ind--)
    {
        for(int tar = 1; tar <= n; tar++)
        {
            int mini = 1e9;

            for(int i = ind; i < perfectSquares.size(); i++)
            {
                if(perfectSquares[i] <= tar)
                {
                    int count = 1+dp[i][tar-perfectSquares[i]];
                    mini = min(mini, count);
                }
            }
            dp[ind][tar] = mini;
        }
    }

    return dp[index][n];
}

int main(){
    return 0;
}