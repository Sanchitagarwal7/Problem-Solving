#include<bits/stdc++.h>
using namespace std;

/*Space Optimisation*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n, 0);

        for(int i = 0; i<m; i++)
        {
            vector<int> temp(n, 0);
            for(int j = 0; j<n; j++)
            {

                if(obstacleGrid[i][j] == 1)
                {
                    temp[j] = 0;
                    continue;
                }

                if(i == 0 && j == 0)
                {
                    temp[j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(i > 0)
                {
                    up = prev[j];
                }
                if(j > 0)
                {
                    left = temp[j-1];
                }

                temp[j] = up + left;
            }
            prev = temp;
        }

        return prev[n-1];
    }
};

/*Tabulation*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {

                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                if(i == 0 && j == 0)
                {
                    dp[i][j] = 1;
                    continue;
                }

                int up = 0;
                int left = 0;

                if(i > 0)
                {
                    up = dp[i-1][j];
                }
                if(j > 0)
                {
                    left = dp[i][j-1];
                }

                dp[i][j] = up + left;
            }
        }

        return dp[m-1][n-1];
    }
};

/*Memoization*/
class Solution {
public:
    int dfs(int &m, int &n, int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp)
    {
        //base case
        if(row>=m || col>=n || obstacleGrid[row][col] == 1)
        {
            return 0;
        }

        if(dp[row][col]!=-1) return dp[row][col];

        if(row==m-1 && col==n-1)
        {
            return 1;
        }

        return dp[row][col] = dfs(m, n, row+1, col, obstacleGrid, dp) + dfs(m, n, row, col+1, obstacleGrid, dp);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return dfs(m, n, 0, 0, obstacleGrid, dp);
    }
};

int main(){
    return 0;
}