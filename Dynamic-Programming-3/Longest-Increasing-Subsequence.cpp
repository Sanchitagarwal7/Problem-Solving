#include<bits/stdc++.h>
using namespace std;


                                /*MEMOIZATION*/

// int solve(vector<int>& nums, int index, int prev, int &n, vector<vector<int>> &dp){
//     //base case
//     if(index>=n) return 0;
//     if(dp[index][prev+1]!=-1) return dp[index][prev+1];

//     //pick, not pick
//     int not_pick = 0+solve(nums, index+1, prev, n, dp);
//     int pick = 0;
//     if(prev==-1 || (prev!=-1 && nums[prev]<nums[index])){
//         pick += 1+solve(nums, index+1, index, n, dp);
//     }
    
//     return dp[index][prev+1] = max(not_pick, pick);
// }


                                /*TABULATION*/

// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();

//     vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

//     for(int i = n-1; i>=0; i--){
//         for(int prev = n-1; prev>=-1; prev--){
//             int not_pick = 0+dp[i+1][prev+1];
//             int pick = 0;
//             if(prev==-1 || (prev!=-1 && nums[prev]<nums[i])){
//                 pick += 1+dp[i+1][i+1];
//             }
            
//             dp[i][prev+1] = max(not_pick, pick);
//         }
//     }

//     return dp[0][0];
// }

                                /*SPACE OPTIMISATION*/

// int lengthOfLIS(vector<int>& nums) {
//     int n = nums.size();

//     vector<int> frwd(n+1, 0);

//     for(int i = n-1; i>=0; i--){

//         vector<int> curr(n+1, 0);

//         for(int prev = n-1; prev>=-1; prev--){
//             int not_pick = 0 + frwd[prev+1];
//             int pick = 0;
//             if(prev==-1 || (prev!=-1 && nums[prev]<nums[i])){
//                 pick += 1 + frwd[i+1];
//             }
            
//             curr[prev+1] = max(not_pick, pick);
//         }

//         frwd = curr;
//     }
//     return frwd[0];
// }

    int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();

    vector<int> temp;
    temp.push_back(nums[0]);

    for(int i = 1; i<n; i++){
        if(nums[i]>temp.back()){
            temp.push_back(nums[i]);
        }else{
            int idx = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[idx] = nums[i];
        }
    }
    return temp.size();
}

int main(){
    return 0;
}