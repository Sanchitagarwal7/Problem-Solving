#include<bits/stdc++.h>
using namespace std;

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<bool> vis(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});    //{cost, node}

    int minCost = 0;

    while(!pq.empty()){
        auto temp = pq.top();
        pq.pop();

        int cost = temp.first;
        int node = temp.second;

        if(vis[node]) continue;

        vis[node] = true;
        minCost+=cost;

        for(int i = 0; i<n; i++)
        {
            //not visited
            if(!vis[i])
            {
                int point = abs(points[node][0]-points[i][0]) + abs(points[node][1]-points[i][1]);

                pq.push({point, i});
            }
        }
    }

    return minCost;
}

int main(){
    return 0;
}