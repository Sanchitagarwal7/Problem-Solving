#include<bits/stdc++.h>
using namespace std;

double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) 
{
    ////////////////////////////////DJIKSTRA ALGO//////////////////////////////////////////////////////////

    vector<pair<double, int>> adjList[n];
    for(int i = 0; i<edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        double prob = succProb[i];

        adjList[u].push_back({prob, v});
        adjList[v].push_back({prob, u});
    }
    //adjacency vector is made

    priority_queue<pair<double, int>> maxHeap; //<probability, node>
    vector<double> dist(n, -1e9);
    dist[start_node] = 1; //probabilty would be 1, as starting node

    //insert into the maxHeap
    maxHeap.push({dist[start_node], start_node});

    while(!maxHeap.empty())
    {
        auto temp = maxHeap.top(); maxHeap.pop();

        double node_prob = temp.first;
        int node = temp.second;

        // if(node == end_node)
        // {
        //   cout << dist[end_node] << endl;
        // }

        for(auto it: adjList[node])
        {
            double adjnode_prob = it.first;
            int adjNode = it.second;

            if(dist[adjNode] < adjnode_prob * node_prob)
            {
                dist[adjNode] = adjnode_prob * node_prob;
                maxHeap.push({dist[adjNode], adjNode});
            }
        }
    }

    if(dist[end_node] == -1e9) return 0;

    return dist[end_node];
}

int main(){
    return 0;
}