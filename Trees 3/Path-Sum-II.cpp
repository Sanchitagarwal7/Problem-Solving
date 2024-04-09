#include<bits/stdc++.h>
using namespace std;

void solve(TreeNode* root, int targetSum, vector<int> path, vector<vector<int>>&res){
    //base case
    if(!root) return ;
    if(root->left==NULL && root->right==NULL){
        if(targetSum-root->val == 0){
            path.push_back(root->val);
            res.push_back(path);
        }
        return ;
    }

    path.push_back(root->val);
    solve(root->left, targetSum-root->val, path, res);
    solve(root->right, targetSum-root->val, path, res);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> res;
    vector<int> path;

    solve(root, targetSum, path, res);

    return res;
}

int main(){
    return 0;
}