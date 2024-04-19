#include<bits/stdc++.h>
using namespace std;

int Solution::knight(int A, int B, int C, int D, int E, int F) {
    
    vector<vector<bool>> vis(A+1, vector<bool>(B+1, false));
    
    queue<pair<pair<int, int>, int>> q;
    q.push({{C, D}, 0});
    vis[C][D] = true;
    
    int mini = 1e9;
    
    //8-directions
    int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        
        int row = temp.first.first;
        int col = temp.first.second;
        
        int time = temp.second;
        
        if(row==E && col==F){
            mini = min(mini, time);
        }
        
        for(int i = 0; i<8; i++){
            int newR = row+dr[i];
            int newC = col+dc[i];
            
            if(newR >=1 && newR <= A && newC >= 1 && newC <= B && !vis[newR][newC]){
                //mark visited
                vis[newR][newC] = true;
                q.push({{newR, newC}, time+1});
            }
        }
    }
    return mini==1e9 ? -1 : mini;
}

int main(){
    return 0;
}