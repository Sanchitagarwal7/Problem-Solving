#include<bits/stdc++.h>
using namespace std;

vector <int> bottomView(Node *root) {
    map<int, int> mp;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        int size=q.size();
        
        for(int i = 0; i<size; i++){
            auto temp = q.front(); q.pop();
            
            mp[temp.second] = temp.first->data;
            
            if(temp.first->left){
                q.push({temp.first->left, temp.second-1});
            }
            
            if(temp.first->right){
                q.push({temp.first->right, temp.second+1});
            }
        }
    }
    
    vector<int> res;
    
    for(auto it: mp){
        res.push_back(it.second);
    }
    
    return res;
    
}

int main(){
    return 0;
}