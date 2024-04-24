#include<bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //step 1 to make the adjacency list

    vector<pair<int, int>> adj[n];
    for(auto it: flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    //adjacency list is made
    
    queue<pair<int, pair<int, int> > > q;
    //{stops, {node, cost}}
    q.push({0, {src, 0}});

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    //distance array is made
    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if(stops>k) continue; //if stops are greater than k then just skip to next iteration

        for(auto it: adj[node])
        {
            int adjNode = it.first;
            int edgeW = it.second;

            if(dist[adjNode] > cost+edgeW && (stops<=k))
            {
                dist[adjNode] = cost+edgeW;
                q.push({stops+1, {adjNode, cost+edgeW}});
            }
        }
    }

    //if cost of dst node is still infinty, that means we never reached it hence return -1
    if(dist[dst]==1e9) return -1;
    return dist[dst];   //else return its cost
}

int main(){
    return 0;
}