#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root==NULL) return {};

    vector<vector<int>> res;

    queue<TreeNode* > q;
    q.push(root);

    while(!q.empty()){
        int size = q.size();

        vector<int> temp;

        for(int i = 0; i<size; i++){
            auto node = q.front(); q.pop();

            temp.push_back(node->val);

            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }

        res.push_back(temp);
    }

    return res;
}

int main(){
    return 0;
}