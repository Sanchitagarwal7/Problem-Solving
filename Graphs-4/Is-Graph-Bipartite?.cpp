#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>>& graph, int &V, vector<int> &colored, int color, int src)
{
    colored[src] = color;

    for(auto it: graph[src])
    {
        if(colored[it] == -1)
        {
            if(dfs(graph, V, colored, !color, it)  == false){
                return false;
            }
        }
        else if(colored[it] == colored[src]) return false; //same color == cant be bipartite
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int V = graph.size();

    vector<int> colored(V, -1);

    for(int i = 0; i<V; i++)  //for connected components
    {
        if(colored[i] == -1)
        {
            //not colored
            if(dfs(graph, V, colored, 0, i) == false)
            {
                return false;
            }
        }
    }
    return true;
}

int main(){
    return 0;
}