#include<bits/stdc++.h>
using namespace std;

/*MEMOIZATION*/
// int solve(int n, vector<int>& dp){
//     //base case
//     if(n==1) return 1;
//     if(n==2) return 2;
//     if(dp[n]!=-1) return dp[n];
    
//     return dp[n] = countFriendsPairings(n-1) + (n-1)*countFriendsPairings(n-2); 
// }


/*TABULATION*/
// int countFriendsPairings(int n) 
// {
//     int MOD = 1e9+7;
//     vector<long long> dp(n+1, 0); 
//     dp[1] = 1;
//     dp[2] = 2;
    
//     for(int i = 3; i<=n; ++i){
//         dp[i] = (dp[i-1]+((i-1)*dp[i-2])%MOD)%MOD;
//     }
    
//     return dp[n]%MOD;
// }

//SPACE OPTIMISATION
int countFriendsPairings(int n) 
{
    if(n==1) return 1;
    if(n==2) return 2;
    
    int MOD = 1e9+7;

    long long p1 = 1;
    long long p2 = 2;
    
    for(int i = 3; i<=n; ++i){
        long long curr = (p2+((i-1)*p1)%MOD)%MOD;
        p1 = p2;
        p2 = curr;
    }
    
    return p2%MOD;
}

int main(){
    return 0;
}