#include<bits/stdc++.h>
using namespace std;

vector<int> rightSideView(TreeNode* root) {
    if(root == NULL) return {};

    map<int, int> lvlToNode;

    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        int size = q.size();

        for(int i = 0; i<size; i++){
            auto temp = q.front(); q.pop();

            lvlToNode[temp.second] = temp.first->val;

            if(temp.first->left){
                q.push({temp.first->left, temp.second+1});
            }
            if(temp.first->right){
                q.push({temp.first->right, temp.second+1});
            }
        }
    }
    vector<int> res;
    for(auto it: lvlToNode){
        res.push_back(it.second);
    }
    return res;
}

int main(){
    return 0;
}