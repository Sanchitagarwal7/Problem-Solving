#include<bits/stdc++.h>
using namespace std;

//dfs approach
void dfs(vector<vector<char>>& grid, int &n, int &m, int row, int col, vector<vector<bool>> &vis){
    //mark visited
    vis[row][col] = true;

    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {-1, 1, 0, 0};

    for(int i = 0; i<4; i++){
        int newR = row + dr[i];
        int newC = col + dc[i];

        if(newR >=0 && newR < n && newC >=0 && newC<m && !vis[newR][newC] && grid[newR][newC]=='1'){
            dfs(grid, n, m, newR, newC, vis);
        }
    }
}

//bfs approach
void bfs(vector<vector<char>>& grid, int srow, int scol, int &n, int &m){
    queue<pair<int, int>> q;
    q.push({srow, scol});
    grid[srow][scol] = '0';

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    while(!q.empty()){
        auto temp = q.front(); q.pop();

        int row = temp.first;
        int col = temp.second;

        for(int i = 0; i<4; i++){
            int newR = row + dr[i];
            int newC = col + dc[i];

            if(newR>=0 && newR<n && newC>=0 && newC<m && grid[newR][newC]=='1'){
                grid[newR][newC] = '0';
                q.push({newR, newC});
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    int distinctIslands = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && grid[i][j]=='1'){
                distinctIslands++;
                // dfs(grid, n, m, i, j, vis);
                bfs(grid, i, j, n, m);
            }
        }
    }
    return distinctIslands;
}

int main(){
    return 0;
}