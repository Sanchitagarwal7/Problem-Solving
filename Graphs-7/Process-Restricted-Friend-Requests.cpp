#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> parent, rank;
        DisjointSet(int n){
            parent.resize(n);
            rank.resize(n, 0);

            for(int i = 0; i<n; i++) parent[i] = i;
        }

        int findPar(int u){
            if(parent[u]==u) return u;
            return parent[u] = findPar(parent[u]);
        }

        void unionByRank(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);

            if(ult_u==ult_v) return ;
            if(rank[ult_u] > rank[ult_v]){
                parent[ult_v] = ult_u;
            }else if(rank[ult_u] < rank[ult_v]){
                parent[ult_u] = ult_v;
            }else{
                parent[ult_v] = ult_u;
                rank[ult_u]++;
            }
        }
};

vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
    int m = requests.size();

    DisjointSet *ds = new DisjointSet(n);

    vector<bool> res(m);

    for(int i = 0; i<m; i++){
        int u = requests[i][0];
        int v = requests[i][1];

        //their ult parents
        int ult_u = ds->findPar(u);
        int ult_v = ds->findPar(v);

        bool canBeFriends = true;

        for(auto blocks: restrictions){
            int u1 = blocks[0];
            int v1 = blocks[1];

            int ult_u1 = ds->findPar(u1);
            int ult_v1 = ds->findPar(v1);

            //if those requests are in the restrictions then they cant be friends
            if((u==u1 && v==v1) || (u==v1 && v==u1) || (ult_u==ult_u1 && ult_v==ult_v1) 
            || (ult_u==ult_v1 && ult_v==ult_u1)){
                canBeFriends = false;
                break;
            }
        }

        res[i] = canBeFriends;
        if(!canBeFriends) continue;
        ds->unionByRank(u, v); //make them friends
    }

    return res;
}

int main(){
    return 0;
}