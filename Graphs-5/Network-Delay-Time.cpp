#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    //lets first make the adjacency list since its a directed graph
    //of nodes n
    vector<pair<int, int>> adj[n+1];

    for(int i = 0; i<times.size(); i++)
    {
        adj[times[i][0]].push_back({times[i][1], times[i][2]});
    }
    //adjacency list is made

    //declare min-heap
    priority_queue<pair<int, int>,
    vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    //{starting time is zero, starting node}
    minHeap.push({0, k});

    //min-time vector
    vector<int> minTime(n+1, 1e9);
    minTime[k] = 0;

    while(!minHeap.empty())
    {
        auto temp = minHeap.top();
        minHeap.pop();
        int time = temp.first;
        int node = temp.second;

        for(auto it: adj[node])
        {
            int adjNode = it.first;
            int edTime = it.second;

            if(minTime[adjNode] > minTime[node]+edTime)
            {
                minTime[adjNode] = minTime[node]+edTime;

                minHeap.push({minTime[node]+edTime, adjNode});
            }
        }
    }

    int ans = 0;     //to get max time in our min time array

    for(int i = 1; i<minTime.size(); i++)
    {
        ans = max(ans, minTime[i]);    //get max
    }

    //but if our ans is infinty means we didnt reach node hence return -1

    if(ans==1e9) return -1; 

    //else return time
    return ans;
}

int main(){
    return 0;
}