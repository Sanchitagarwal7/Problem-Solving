#include<bits/stdc++.h>
using namespace std;

/*Memoization*/
int solve(vector<vector<int>> &mat, int index, int &n, vector<int> &dp){
    //base case
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];
    
    //pick, non pick approach
    int pick = 0, non_pick = 0;
    
    non_pick = solve(mat, index+1, n, dp);
    
    pick = max(mat[0][index], mat[1][index])+solve(mat, index+2, n, dp);
    
    return dp[index] = max(pick, non_pick);
}
int maxSum(int N, vector<vector<int>> mat)
{
    vector<int> dp(N, -1);
    
    return solve(mat, 0, N, dp);
}


/*Tabulation*/
int maxSum(int N, vector<vector<int>> mat)
{
    vector<int> dp(N+2, 0);
    
    for(int index = N-1; index>=0; index--){
        //pick, non pick approach
        int pick = 0, non_pick = 0;
        
        non_pick = dp[index+1];
        
        pick = max(mat[0][index], mat[1][index])+dp[index+2];
        
        dp[index] = max(pick, non_pick);
    }
    
    return dp[0];
}

/*Space Optimisation*/
int maxSum(int N, vector<vector<int>> mat)
{
    int onePlus = 0;
    int twoPlus = 0;
    
    for(int index = N-1; index>=0; index--){
        //pick, non pick approach
        int pick = 0, non_pick = 0;
        
        non_pick = onePlus;
        
        pick = max(mat[0][index], mat[1][index])+twoPlus;
        
        int curr = max(pick, non_pick);
        
        twoPlus = onePlus;
        onePlus = curr;
    }
    
    return onePlus;
}

int main(){
    return 0;
}