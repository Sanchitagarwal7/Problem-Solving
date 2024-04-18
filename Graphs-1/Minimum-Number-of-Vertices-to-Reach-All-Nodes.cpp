#include<bits/stdc++.h>
using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    //calculate indegree of all vertices and and return ones with indegree 0,becoz we can reach every node via them
    vector<int> indegree(n, 0);

    for(auto it: edges)
    {
        int u = it[0];
        int v = it[1];

        indegree[v]++;
    }

    vector<int> res;

    for(int i = 0; i<n; i++)
    {
        if(indegree[i] == 0)
        {
            res.push_back(i);
        }
    }

    return res;
}

int main(){
    return 0;
}