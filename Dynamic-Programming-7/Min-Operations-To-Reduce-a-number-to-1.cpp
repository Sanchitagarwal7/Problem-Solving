#include<bits/stdc++.h>
using namespace std;

//Code from similar question -> MINIMUM DAYS TO EAT N ORANGES (since there was no question on the link provided)

//MEMOIZATION
// int solve(int n, unordered_map<int, int>& dp){
//     if(n<=1) return n;
//     if(dp.find(n)!=dp.end()) return dp[n];

//     int ways = 1e9;

//     if(n%2==0){
//         ways = min(ways, solve(n/2, dp));
//     }
//     if(n%3==0){
//         ways = min(ways, solve(n/3, dp));
//     }

//     if(n%2 || n%3) //suppose a prime number
//         ways = min(ways, solve(n-1, dp));

//     return dp[n] = 1+ways;
// }
// int minDays(int n) {
//     unordered_map<int, int> dp;
//     return solve(n, dp);
// }

//TABULATION
// int minDays(int n) {
//     vector<int> dp(n+1, 0);
//     dp[1] = 1;
//     dp[2] = 2;
//     dp[3] = 2;

//     for(int i = 4; i<=n; ++i){
//         int ways = 1e9;

//         if(i%2==0){
//             ways = min(ways, dp[i/2]);
//         }
//         if(i%3==0){
//             ways = min(ways, dp[i/3]);
//         }

//         ways = min(ways, dp[i-1]);

//         dp[i] = 1+ways;
//     }

//     return dp[n];
// }

//BFS APPROACH
int minDays(int n) {
    queue<int> q;
    int days = 0;

    q.push(n);

    unordered_map<int, int> dp;

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i<size; ++i){
            auto oranges = q.front(); q.pop();

            if(oranges==0) return days;

            if(oranges%3==0 && dp.find(oranges/3)==dp.end()){
                q.push(oranges/3);
                dp[oranges/3] = days+1;
            }
            if(oranges%2==0 && dp.find(oranges/2)==dp.end()){
                q.push(oranges/2);
                dp[oranges/2] = days+1;
            }

            if(dp.find(oranges-1)==dp.end()){
                q.push(oranges-1);
                dp[oranges-1] = days+1;
            }
        }
        ++days;
    }

    return -1;
}

int main(){
    return 0;
}