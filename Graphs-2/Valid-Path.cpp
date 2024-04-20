#include<bits/stdc++.h>
using namespace std;

string Solution::solve(int X, int Y, int N, int R, vector<int> &x, vector<int> &y) {
    
    vector<vector<bool>> vis(X+1, vector<bool>(Y+1, false));
    
    for(int i = 0; i<=X; i++){
        for(int j = 0; j<=Y; j++){
            for(int k = 0; k<N; k++){
                if( (i-x[k])*(i-x[k]) + (j-y[k])*(j-y[k]) <= R*R ){ //inside or on circumference
                    vis[i][j] = true;
                    break;
                }
            }
        }
    }
    //marked all points which are inside circle as visited
    
    if(vis[0][0]) return "NO"; //if starting is inside circle
    if(vis[X][Y]) return "NO"; //if destination is inside circle
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    vis[0][0] = true;
    
    //8-directions
    int dr[8] = {0, -1, -1, -1, 0, 1, 1, 1};
    int dc[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    
    while(!q.empty()){
        auto temp = q.front(); q.pop();
        
        int xc = temp.first;
        int yc = temp.second;
        
        if(xc==X && yc==Y) return "YES";
        
        for(int i = 0; i<8; i++){
            int newX = xc+dr[i];
            int newY = yc+dc[i];
            
            if(newX>=0 && newX<=X && newY>=0 && newY<=Y && !vis[newX][newY]){
                vis[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }
    return "NO";
}


int main(){
    return 0;
}