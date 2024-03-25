#include<bits/stdc++.h>
using namespace std;

vector<int> topView(Node *root)
{
    //can do it with using horital axis only
    map<int, int> horiLevel;
    
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    
    while(!q.empty()){
        int size = q.size();
        
        for(int i = 0; i<size; i++){
            auto temp = q.front(); q.pop();
            
            if(horiLevel.find(temp.second)==horiLevel.end()){
                horiLevel[temp.second] = temp.first->data;
            }
            
            if(temp.first->left){
                q.push({temp.first->left, temp.second-1});
            }
            
            if(temp.first->right){
                q.push({temp.first->right, temp.second+1});
            }
        }
    }
    
    vector<int> res;
    for(auto it: horiLevel){
        res.push_back(it.second);
    }
    
    return res;
}

int main(){
    return 0;
}