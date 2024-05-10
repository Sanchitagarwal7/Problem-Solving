#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size();

    vector<int> dp(n, -1);
    dp[0] = nums[0];
    int maxSum = dp[0];

    for(int i = 1; i<n; i++){
        if(dp[i-1]>0){
            dp[i] = nums[i]+dp[i-1];
        }else{
            dp[i] = nums[i];
        }
        maxSum = max(maxSum, dp[i]);
    }

    return maxSum;

}

int main(){
    return 0;
}