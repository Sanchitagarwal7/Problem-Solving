#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>nearest(vector<vector<int>>grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    vector<vector<int>> res(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j]==1){
                res[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};
    
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        
        int row = temp.first;
        int col = temp.second;
        
        for(int i = 0; i<4; i++){
            int newR = row + dr[i];
            int newC = col + dc[i];
            
            if(newR>=0 && newR<n && newC>=0 && newC<m && res[newR][newC]==-1){
                res[newR][newC] = res[row][col]+1;
                q.push({newR, newC});
            }
        }
    }
    
    return res;
}

int main(){
    return 0;
}