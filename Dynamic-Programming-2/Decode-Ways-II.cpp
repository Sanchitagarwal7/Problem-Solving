#include<bits/stdc++.h>
using namespace std;

                                        /*Memoization*/
int mod = 1e9+7;
long long solve(string &s, int index, int &n, vector<long long> &dp){
    //base case
    if(index>=n) return 1;
    if(s[index]=='0') return 0;
    if(dp[index]!=-1) return dp[index];

    long long ways = 0;

    //lets first handle *
    if(s[index]=='*'){
        //single digit pick
        ways = (ways + (9*solve(s, index+1, n, dp))%mod)%mod;

        //double digit pick
        if(index+1<n && (s[index+1]>='0' && s[index+1]<='6')){
            ways = (ways + (2*solve(s, index+2, n, dp))%mod)%mod;
        }else if(index+1<n && s[index+1]=='*'){
            ways = (ways + (15*solve(s, index+2, n, dp))%mod)%mod;
        }else if(index+1<n){
            ways = (ways + solve(s, index+2, n, dp))%mod;
        }

    }else if(s[index]!='*'){
        //single digit pick
        ways = (ways + solve(s, index+1, n, dp))%mod;

        //double digit pick
        if(index+1<n && s[index]=='1'){
            if(s[index+1]=='*'){
                ways = (ways + (9*solve(s, index+2, n, dp))%mod)%mod;
            }else if(s[index+1]>='0' && s[index+1]<='9'){
                ways = (ways + solve(s, index+2, n, dp))%mod;
            }
        }
        else if(index+1<n && s[index]=='2'){
            if(s[index+1]=='*'){
                ways = (ways + (6*solve(s, index+2, n, dp))%mod)%mod;
            }else if(s[index+1]>='0' && s[index+1]<='6'){
                ways = (ways + solve(s, index+2, n, dp))%mod;
            }
        }
    }

    return dp[index] = ways;
    
}
int numDecodings(string s) {
    int n = s.length();

    vector<long long> dp(n+1, -1);
    int index = 0;

    return solve(s, index, n, dp)%mod;
}

int main(){
    return 0;
}