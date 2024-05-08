#include<bits/stdc++.h>
using namespace std;

/*Memoization*/
class Solution {
public:
    int solve(vector<vector<int>>& grid, int row, int col, int &m, int &n, vector<vector<int>> &dp)
    {
        //base case
        if(row<0 || row>=m || col<0 || col>=n)
        {
            return 1e9;
        }

        if(dp[row][col]!=-1) return dp[row][col];

        if(row == m-1 && col == n-1)
        {
            return grid[row][col];
        }

        int down = grid[row][col] + solve(grid, row+1, col, m, n, dp);
        int right = grid[row][col] + solve(grid, row, col+1, m, n, dp);

        return dp[row][col] = min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        int row = 0;
        int col = 0;

        return solve(grid, row, col, m, n, dp);
    }
};

/*Tabulation*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                    {
                        up+=dp[i-1][j];
                    }
                    else
                    {
                        up+=1e9;
                    }

                    int left = grid[i][j];
                    if(j>0)
                    {
                        left+=dp[i][j-1];
                    }
                    else
                    {
                        left+=1e9;
                    }

                    dp[i][j] = min(up, left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};

/*Space Optimisation*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i<m; i++)
        {
            vector<int> temp(n, 0);
            for(int j = 0; j<n; j++)
            {
                if(i == 0 && j == 0)
                {
                    temp[j] = grid[i][j];
                }
                else
                {
                    int up = grid[i][j];
                    if(i>0)
                    {
                        up+=prev[j];
                    }
                    else
                    {
                        up+=1e9;
                    }

                    int left = grid[i][j];
                    if(j>0)
                    {
                        left+=temp[j-1];
                    }
                    else
                    {
                        left+=1e9;
                    }

                    temp[j] = min(up, left);
                }
            }
            prev = temp;
        }
        return prev[n-1];
    }
};

int main(){
    return 0;
}