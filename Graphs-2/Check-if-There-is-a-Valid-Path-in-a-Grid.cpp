#include<bits/stdc++.h>
using namespace std;

bool isvalid(int &row, int &col, int &n, int &m, vector<vector<bool>> &vis){
    if(row < 0 || row >= n || col < 0 || col>=m || vis[row][col]){
        return false;
    }
    return true;
}

// MY INITIAL CODE


// void dfs(vector<vector<int>>& grid, int row, int col, int &n, int &m, vector<vector<bool>> &vis){
//         //mark visited
//         vis[row][col] = true;

//         //reached destination
//         if(row==n-1 && col==m-1) return ;

//         int street = grid[row][col];
//         int newR, newC;

//         if(street==1){
//             //connects left and right
//             //left
//             newR = row, newC = col-1;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==4 || grid[newR][newC]==6 || grid[newR][newC]==1)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//             //right
//             newR = row, newC = col+1;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==3 || grid[newR][newC]==5 || grid[newR][newC]==1)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//         }
//         else if(street==2){
//             //connects up and down
//             //up
//             newR = row-1, newC = col;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==3 || grid[newR][newC]==4 || grid[newR][newC]==2)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//             //down
//             newR = row+1, newC = col;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==5 || grid[newR][newC]==6 || grid[newR][newC]==2)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//         }else if(street==3){
//             //connects left and down
//             //left
//             newR = row, newC = col-1;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==4 || grid[newR][newC]==6 || grid[newR][newC]==1)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//             //down
//             newR = row+1, newC = col;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==5 || grid[newR][newC]==6 || grid[newR][newC]==2)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//         }else if(street==4){
//             //right
//             newR = row, newC = col+1;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==3 || grid[newR][newC]==5 || grid[newR][newC]==1)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//             //down
//             newR = row+1, newC = col;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==5 || grid[newR][newC]==6 || grid[newR][newC]==2)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//         }else if(street==5){
//             //up
//             newR = row-1, newC = col;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==3 || grid[newR][newC]==4 || grid[newR][newC]==2)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//             //left
//             newR = row, newC = col-1;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==4 || grid[newR][newC]==6 || grid[newR][newC]==1)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//         }else if(street==6){
//             //up
//             newR = row-1, newC = col;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==3 || grid[newR][newC]==4 || grid[newR][newC]==2)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//             //right
//             newR = row, newC = col+1;
//             if(isvalid(newR, newC, n, m, vis) && (grid[newR][newC]==3 || grid[newR][newC]==5 || grid[newR][newC]==1)){
//                 dfs(grid, newR, newC, n, m, vis);
//             }
//         }
// }

void dfs(vector<vector<int>>& grid, int row, int col, int &n, int &m, vector<vector<bool>> &vis){
    //mark visited
    vis[row][col] = true;

    //reached destination
    if(row==n-1 && col==m-1) return ;

    int street = grid[row][col];
    int newR, newC;

    //left
    newR = row, newC = col-1;
    if(isvalid(newR, newC, n, m, vis) && (street == 1 || street == 3 || street == 5) && (grid[newR][newC]==1 || grid[newR][newC]==4 || grid[newR][newC]==6)){
        dfs(grid, newR, newC, n, m, vis);
    }

    //right
    newR = row, newC = col+1;
    if(isvalid(newR, newC, n, m, vis) && (street == 1 || street == 4 || street == 6) && (grid[newR][newC]==1 || grid[newR][newC]==3 || grid[newR][newC]==5)){
        dfs(grid, newR, newC, n, m, vis);
    }

    //up
    newR = row-1, newC = col;
    if(isvalid(newR, newC, n, m, vis) && (street == 2 || street == 5 || street == 6) && (grid[newR][newC]==2 || grid[newR][newC]==3 || grid[newR][newC]==4)){
        dfs(grid, newR, newC, n, m, vis);
    }
    //down
    newR = row+1, newC = col;
    if(isvalid(newR, newC, n, m, vis) && (street == 2 || street == 3 || street == 4) && (grid[newR][newC]==2 || grid[newR][newC]==5 || grid[newR][newC]==6)){
        dfs(grid, newR, newC, n, m, vis);
    }
}

bool hasValidPath(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    dfs(grid, 0, 0, n, m, vis);

    return vis[n-1][m-1];
}

int main(){
    return 0;
}