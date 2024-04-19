#include<bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    int fresh = 0, newRotten = 0;
    queue<pair<pair<int, int>, int>> q; //<row, col, time>

    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j]==2){
                vis[i][j] = 2;
                q.push({{i, j}, 0});
            }
            if(grid[i][j]==1){
                fresh++;
            }
        }
    }

    //do bfs since we are travesing not in depth but equally in all directions
    int dr[4] = {0, 0, -1, 1};
    int dc[4] = {1, -1, 0, 0};

    int maxi = 0;

    while(!q.empty()){
        auto temp = q.front(); q.pop();

        int row = temp.first.first;
        int col = temp.first.second;

        int time = temp.second;

        maxi = max(maxi, time);

        for(int i = 0; i<4; i++){
            int newR = row + dr[i];
            int newC = col + dc[i];

            if(newR>=0 && newR<n && newC>=0 && newC<m && vis[newR][newC]==0 && grid[newR][newC]==1){
                //mark rotten
                vis[newR][newC] = 2;
                newRotten++;
                q.push({{newR, newC}, time+1});
            }
        }
    }

    if(fresh!=newRotten) return -1;     //all oranges are did not get rotten

    return maxi;
}

int main(){
    return 0;
}