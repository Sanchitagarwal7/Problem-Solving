#include<bits/stdc++.h>
using namespace std;

bool dfs(int &V, vector<int> adj[],vector<int> &vis, vector<int> &pathvis, int src)
{
    vis[src] = 1;
    pathvis[src] = 1;
    
    for(auto it: adj[src])
    {
        if(!vis[it])
        {
            if(dfs(V, adj, vis, pathvis, it) == true){
                return true;
            }
        }
        else if(pathvis[it] == 1) return true; 
    }
    pathvis[src] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    vector<int> pathvis(V, 0);
    
    for(int i = 0; i<V; i++)
    {
        if(!visited[i])
        {
            if(dfs(V, adj, visited, pathvis, i) == true)
            {
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    return 0;
}