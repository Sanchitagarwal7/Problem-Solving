#include<bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();

    priority_queue<pair<int, pair<int, int> > , 
    vector<pair<int, pair<int, int>  > >,
    greater<pair<int, pair<int, int> > > > minHeap; 

    vector<vector<int> > dist(m, vector<int>(n, 1e9));


    dist[0][0] = 0;

    minHeap.push({0, {0, 0}});

    //now to apply djikstra's algo to find the shortest distance
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!minHeap.empty())
    {
        auto temp = minHeap.top();
        int effort = temp.first;
        int row = temp.second.first;
        int col = temp.second.second;
        minHeap.pop();

        if(row == m-1 && col == n-1)    
        {
            return effort;
        }

        for(int i = 0; i<4; i++)    
        {
            int newR = row+dr[i];
            int newC = col+dc[i];

            if(newR>=0 && newR<m && newC>=0 && newC<n)  //check validity
            {
                int newEffort = max(effort, abs(heights[row][col]-heights[newR][newC])); //get the max effort of each route

                if(dist[newR][newC]>newEffort)  //if new effort is less than the existing effort (minimum effort)
                {
                    dist[newR][newC] = newEffort;          //replace its value
                    minHeap.push({newEffort, {newR, newC}});  //push into the minHeap
                }
            }
        }
    }
    return 0;     
}

int main(){
    return 0;
}