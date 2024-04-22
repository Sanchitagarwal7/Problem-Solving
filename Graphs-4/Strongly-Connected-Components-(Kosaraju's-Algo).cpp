#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<bool> &vis, stack<int> &st, int node){
    //mark visited
    vis[node] = true;
    
    for(auto adjNode: adj[node]){
        if(!vis[adjNode]){
            dfs(adj, vis, st, adjNode);
        }
    }
    st.push(node);
}

void dfs1(vector<int> revList[], vector<bool> &vis, int node){
    //mark visited
    vis[node] = true;
    
    for(auto adjNode: revList[node]){
        if(!vis[adjNode]){
            dfs1(revList, vis, adjNode);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj)
{
    stack<int> st;
    vector<bool> vis(V, false);
    
    //dfs to populate stack
    for(int i = 0; i<V; i++){
        if(!vis[i]){
            dfs(adj, vis, st, i);
        }
    }
    
    //reverse all edges
    vector<int> revList[V];
    
    for(int u = 0; u<V; u++){
        vis[u] = false;
        for(auto it: adj[u]){
            revList[it].push_back(u);
        }
    }
    
    //dfs to count scc
    int scc = 0;
    
    while(!st.empty()){
        auto node = st.top(); st.pop();
        
        if(!vis[node]){
            scc++;
            dfs1(revList, vis, node);
        }
    }
    
    return scc;
}

int main(){
    return 0;
}