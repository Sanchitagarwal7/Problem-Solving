#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, vector<int>& multipliers, int i, int k, int& n, int& m, vector<vector<int>>& dp){
    //base case
    if(k==m) return 0;
    if(dp[i][k]!=-1) return dp[i][k];

    int maxi = INT_MIN;
    int j = n-1-(k-i); //derived formula to calculate j

    int score1 = nums[i]*multipliers[k] + solve(nums, multipliers, i+1, k+1, n, m, dp);
    int score2 = nums[j]*multipliers[k] + solve(nums, multipliers, i, k+1, n, m, dp);

    maxi = max(maxi, max(score1, score2));

    return dp[i][k] = maxi;
}
int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();

    int i = 0, k = 0;

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return solve(nums, multipliers, i, k, n, m, dp);
}

int main(){
    return 0;
}