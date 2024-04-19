#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &board, int &n, int &m, vector<vector<bool>> &vis, int row, int col){
    //base case
    if(row < 0 || row==n || col<0 || col==m || vis[row][col] || board[row][col]=='X'){
        return ;
    }
    
    vis[row][col] = true;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    for(int i = 0; i<4; i++){
        int newR = row+dr[i];
        int newC = col+dc[i];

        dfs(board, n, m, vis, newR, newC);
    }
}
void solve(vector<vector<char>>& board) {
    //traverse all 4 sides and do a dfs to all uncaptured regions and
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    //traverse all 4 sides
    //1st row
    for(int col = 0; col<m; col++){
        dfs(board, n, m, vis, 0, col);
    }
    //1st col
    for(int row = 0; row<n; row++){
        dfs(board, n, m, vis, row, 0);
    }
    //last row
    for(int col = 0; col<m; col++){
        dfs(board, n, m, vis, n-1, col);
    }
    //last col
    for(int row = 0; row<n; row++){
        dfs(board, n, m, vis, row, m-1);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(!vis[i][j] && board[i][j]=='O'){
                board[i][j] = 'X';
            }
        }
    }
}

int main(){
    return 0;
}