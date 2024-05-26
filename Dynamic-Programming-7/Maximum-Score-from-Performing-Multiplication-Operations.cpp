#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION
// int solve(vector<int>& nums, vector<int>& multipliers, int i, int k, int& n, int& m, vector<vector<int>>& dp){
//     //base case
//     if(k==m) return 0;
//     if(dp[i][k]!=-1) return dp[i][k];

//     int maxi = INT_MIN;
//     int j = n-1-(k-i); //derived formula to calculate j

//     int score1 = nums[i]*multipliers[k] + solve(nums, multipliers, i+1, k+1, n, m, dp);
//     int score2 = nums[j]*multipliers[k] + solve(nums, multipliers, i, k+1, n, m, dp);

//     maxi = max(maxi, max(score1, score2));

//     return dp[i][k] = maxi;
// }
// int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//     int n = nums.size();
//     int m = multipliers.size();

//     int i = 0, k = 0;

//     vector<vector<int>> dp(n, vector<int>(m, -1));

//     return solve(nums, multipliers, i, k, n, m, dp);
// }


//TABULATION
// int maximumScore(vector<int>& nums, vector<int>& multipliers) {
//     int n = nums.size();
//     int m = multipliers.size();

//     vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

//     for(int i = n-1; i>=0; i--){
//         for(int k = m-1; k>=0; k--){
//             int maxi = INT_MIN;
//             int j = n-1-abs(k-i); //derived formula to calculate j

//             int score1 = nums[i]*multipliers[k] + dp[i+1][k+1];
//             int score2 = nums[j]*multipliers[k] + dp[i][k+1];

//             maxi = max(maxi, max(score1, score2));

//             dp[i][k] = maxi;
//         }
//     }

//     return dp[0][0];
// }

//SPACE OPTIMISATION
int maximumScore(vector<int>& nums, vector<int>& multipliers) {
    int n = nums.size();
    int m = multipliers.size();

    vector<int> temp(m+1, 0);

    for(int i = n-1; i>=0; i--){
        vector<int> curr(m+1, 0);
        for(int k = m-1; k>=0; k--){
            int maxi = INT_MIN;
            int j = n-1-abs(k-i); //derived formula to calculate j

            int score1 = nums[i]*multipliers[k] + temp[k+1];
            int score2 = nums[j]*multipliers[k] + curr[k+1];

            maxi = max(maxi, max(score1, score2));

            curr[k] = maxi;
        }

        temp = curr;
    }

    return temp[0];
}

int main(){
    return 0;
}