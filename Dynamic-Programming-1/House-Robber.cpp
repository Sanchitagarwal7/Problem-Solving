#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION
int solve(vector<int>&nums, int index, vector<int>&dp)
{
    //bae case
    if(index<0)
    {
        return 0;
    }
    if(dp[index] != -1)
    {
        return dp[index];
    }
    if(index==0)
    {
        return dp[index] = nums[index];
    }
    int pick = nums[index]+solve(nums, index-2, dp);
    int not_pick = 0+solve(nums, index-1, dp);

    return dp[index] = max(pick, not_pick);
}

int rob(vector<int>& nums) {
    int index = nums.size()-1;
    vector<int> dp(nums.size(), -1);

    return solve(nums, index, dp);
}

//TABULATION
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, -1);

    dp[0] = nums[0];

    for(int i = 1; i<n; i++)
    {
        int not_pick = 0+dp[i-1];
        int pick = nums[i];
        if(i>1)
        {
            pick+=dp[i-2];
        }

        dp[i] = max(pick, not_pick);
    }

    return dp[n-1];
}


//Bottom-up-> O(1)
int rob(vector<int>& nums) {
    int n = nums.size();

    int prev1 = nums[0];
    int prev2 = 0;

    for(int i = 1; i<n; i++)
    {
        int pick = nums[i];
        if(i>1)
        {
            pick+=prev2;
        }

        int not_pick = 0+prev1;

        int curr = max(pick, not_pick);

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main(){
    return 0;
}