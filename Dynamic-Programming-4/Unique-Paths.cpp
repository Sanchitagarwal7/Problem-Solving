#include<bits/stdc++.h>
using namespace std;

/*Space Optimisation*/
int uniquePaths(int m, int n) {
    vector<int> prev(n, 0);

    prev[0] = 1;

    for(int i = 0; i<m; i++)
    {
        vector<int>temp(n, 0);
        for(int j = 0; j<n; j++)
        {
            int up = prev[j];
            int left = 0;
            if(j>0)
            {
                left = temp[j-1];
            }
            temp[j] = up + left;
        }
        prev = temp;
    }

    return prev[n-1];
}

/*Tabulation*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        dp[0][0] = 1;

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int left = 0;
                    int up = 0;

                    if(j>0) left = dp[i][j-1];
                    if(i>0) up = dp[i-1][j];

                    dp[i][j] = left+up;
                }
            }
        }

        return dp[m-1][n-1];
    }
};


/*Memoization*/
class Solution {
public:
    int dfs(int m, int n, int row, int col, vector<vector<int>>&dp)
    {
        //base case
        if(row == m-1 && col == n-1)
        {
            return 1;
        }

        if(row<m && col<n)
        {
            if(dp[row][col]!=-1) return dp[row][col];
            //right //bottom
            return dp[row][col] = dfs(m, n, row, col+1, dp) + dfs(m, n, row+1, col, dp);       
        }
        return 0;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m, n, 0, 0, dp);
    }
};

int main(){
    return 0;
}