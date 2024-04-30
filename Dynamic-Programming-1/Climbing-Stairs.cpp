#include<bits/stdc++.h>
using namespace std;

//memoization
int solve(int n, vector<int> &dp){
    //base case
    if(n<=2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}
int climbStairs(int n) {
    vector<int> dp(n+1, -1);

    return solve(n, dp);
}


//bottom-up O(n) space
int climbStairs(int n) {
    vector<int> dp(n+1, -1);

    dp[0] = dp[1] = 1;

    for(int i = 2; i<=n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}


//bottom-up O(1) space
int climbStairs(int n) {
    int curr;
    int prev = 1;
    int prev2 = 1;

    if(n<2)
    {
        return 1;
    }
    for(int i = 2; i<=n; i++)
    {
        curr = prev+prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}

int main(){
    return 0;
}