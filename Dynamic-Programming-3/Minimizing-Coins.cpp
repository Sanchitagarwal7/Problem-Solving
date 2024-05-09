
#include<bits/stdc++.h>
using namespace std;

/*MEMOIZATION*/
// int solve(vector<int> &coins, int sum, vector<int > &dp){
//     //base case
//     if(sum==0){
//         return 0;
//     }
//     if(sum<0){
//         return 1e9;
//     }
//     if(dp[sum]!=-1) return dp[sum];

//     int minCoins = 1e9;

//     for(int i = 0; i<coins.size(); i++){
//         minCoins = min(minCoins, 1+solve(coins, sum-coins[i], dp));
//     }

//     return dp[sum] = minCoins;
// }

/*TABULATION*/
int main(){
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i = 0; i <= n-1; i++){
        cin >> coins[i];
    }

    vector<int> dp(x+1, 0);

    for(int sum = 1; sum<=x; sum++){
        int minCoins = 1e9;

        for(int i = 0; i<n; i++){
            if(sum-coins[i]>=0)
                minCoins = min(minCoins, 1+dp[sum-coins[i]]);
        }

        dp[sum] = minCoins;
    }

    if(dp[x]==1e9) cout << -1 << endl;
    else cout << dp[x] << endl;

    return 0;
}