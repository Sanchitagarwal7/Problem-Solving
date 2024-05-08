#include<bits/stdc++.h>
using namespace std;


                                            /*MEMOIZATION*/
class Solution {
public:
    int solve(vector<vector<int>>& grid, vector<vector<int>>& moveCost, int cell, int row, int &n, int &m, vector<vector<int>> &dp){
        //base case
        if(row==n-1){
            return cell;
        }
        if(dp[cell][row]!=-1) return dp[cell][row];

        int mini = 1e9;
        for(int i = 0; i<m; i++){
            // cout << "Going from: " << "cell : " << cell << " -> " << grid[row+1][i] << " with cost: " << moveCost[cell][i] << endl;
            mini = min(mini, cell + moveCost[cell][i] + solve(grid, moveCost, grid[row+1][i], row+1, n, m, dp));
        }
        return dp[cell][row] = mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n*m, vector<int>(n, -1));

        int minCost = 1e9;
        //we can start from any cell from first row
        for(int col = 0; col<m; col++){
            int cell = grid[0][col];

            minCost = min(minCost, solve(grid, moveCost, cell, 0, n, m, dp));
        }

        return minCost;
    }
};

                                        /*TABULATION*/
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));

        //base case
        for(int i = 0; i<m; i++){
            int cell = grid[n-1][i];
            dp[n-1][i] = cell;
        }
        //last row is filled so lets start with second last

        for(int row = n-2; row>=0; row--){
            for(int col = 0; col<m; col++){

                int mini = 1e9;
                for(int nxtCol = 0; nxtCol<m; nxtCol++){
                    mini = min(mini, grid[row][col] + moveCost[grid[row][col]][nxtCol] + dp[row+1][nxtCol]);
                }

                dp[row][col] = mini;
            }
        }

        //traverse the first row of dp to get minimum value
        int minCost = 1e9;
        for(int i = 0; i<m; i++){
            minCost = min(minCost, dp[0][i]);
        }

        return minCost;
    }
};

                                    /*SPACE OPTIMISATION*/
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> nicheWaaliRow(m, 0);

        //base case
        for(int i = 0; i<m; i++){
            int cell = grid[n-1][i];
            nicheWaaliRow[i] = cell;
        }
        //last row is filled so lets start with second last

        for(int row = n-2; row>=0; row--){
            vector<int> currRow(m, 0);

            for(int col = 0; col<m; col++){

                int mini = 1e9;
                for(int nxtCol = 0; nxtCol<m; nxtCol++){
                    mini = min(mini, grid[row][col] + moveCost[grid[row][col]][nxtCol] + nicheWaaliRow[nxtCol]);
                }

                currRow[col] = mini;
            }

            nicheWaaliRow = currRow;
        }

        //traverse the first row of dp to get minimum value
        int minCost = 1e9;
        for(int i = 0; i<m; i++){
            minCost = min(minCost, nicheWaaliRow[i]);
        }

        return minCost;
    }
};

int main(){
    return 0;
}