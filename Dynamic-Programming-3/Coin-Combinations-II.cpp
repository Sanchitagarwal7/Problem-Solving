#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int main(){
    int n, x;

    cin >> n >> x;
    vector<int> nums(n);

    for(int i = 0; i<n; i++){
        cin >> nums[i];
    }

    vector<vector<int> > dp(n+1, vector<int>(x+1, 0));

    for(int i = 0; i<n; i++)
    {
        dp[i][0] = 1;
    }

    for(int ind = n-1; ind>=0; ind--){
        for(int tar = 1; tar<=x; tar++){
            int not_take = dp[ind+1][tar];
            int take = 0;

            if(nums[ind]<=tar){
                take = dp[ind][tar-nums[ind]];
            }

            dp[ind][tar] = (not_take + take)%mod;
        }
    }

    cout << dp[0][x]%mod << endl;

    return 0;
}