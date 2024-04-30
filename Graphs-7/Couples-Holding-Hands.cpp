#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> parent, rank;
        
        DisjointSet(int n){
            parent.resize(n);
            rank.resize(n, 0);

            for(int i = 0; i<n; i++){
                parent[i] = i;
            }
        }

        int findPar(int &u){
            //base case
            if(parent[u]==u){
                return u;
            }
            return parent[u] = findPar(parent[u]);
        }

        bool unionByRank(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_u==ult_v) return false;
            if(rank[ult_v] < rank[ult_u]){
                parent[ult_v] = ult_u;
            }else if(rank[ult_u] < rank[ult_v]){
                parent[ult_u] = ult_v;
            }else{
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }

            return true;
        }
};

int minSwapsCouples(vector<int>& row) {
    int n = row.size();

    DisjointSet *ds = new DisjointSet(n);

    //make adjacents a couple
    for(int i = 0; i<n; i+=2){
        ds->unionByRank(row[i], row[i+1]);
    }

    //every i, i+1 should be a couple, if not we need to perform a swap
    int swaps = 0;
    for(int i = 0; i<n; i+=2){
        //{2n-2, 2n-1} are not connected
        if(ds->unionByRank(i, i+1)){
            swaps++; //so swap
        }
    }
    return swaps;
}

int main(){
    return 0;
}