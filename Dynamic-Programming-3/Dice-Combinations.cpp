#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;

/*MEMOIZATION*/
// int solve(int num, int sum, vector<vector<int> > &dp){
//     //base case
//     if(sum==0) return 1;
//     if(num>7) return 0;
//     if(dp[num][sum]!=-1) return dp[num][sum];
//     int ways = 0;
//     for(int i = 1; i <= 6; i++){
//         if(i<=sum){
//             ways = (ways+solve(i+1, sum-i, dp)%MOD)%MOD;
//         }
//     }
//     return dp[num][sum] = ways%MOD;
// }

int main(){
    int n;
    cin >> n;

    vector<int> dp(n+1, 0);
    dp[0] = 1; //we can make 0 sum by 1 way

    for(int sum = 1; sum<=n; sum++){
        for(int num = 1; num<=6; num++){
            if(num<=sum){
                dp[sum] = (dp[sum]+dp[sum-num])%MOD;
            }
        }
    }

    cout << dp[n]%MOD << endl;

    return 0;
}