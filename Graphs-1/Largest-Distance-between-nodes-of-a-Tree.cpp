#include<bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int> adjList[], int &res){
    int maxi = 0;
    
    for(auto adjNode: adjList[node]){
        int dist = dfs(adjNode, adjList, res);
        
        res = max(res, maxi+dist); //max distance till now + distance of further node
        
        maxi = max(maxi, dist);
    }
    
    return 1+maxi;  //plus one edge for current node
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    int root=-1;
    vector<int> adjList[n];
    
    for(int i = 0; i<n; i++){
        if(A[i]!=-1){
            adjList[A[i]].push_back(i);
        }else{
            root = i;
        }
    }
    
    int res = 0;
    
    dfs(root, adjList, res);
    
    return res;
}


int main(){
    return 0;
}