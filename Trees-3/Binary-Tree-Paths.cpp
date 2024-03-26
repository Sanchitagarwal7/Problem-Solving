#include<bits/stdc++.h>
using namespace std;

void dfs(TreeNode* root, vector<string> &res, string path){
    //base case
    if(root==NULL) return ;
    if(root->left==NULL && root->right==NULL){
        path+="->"+to_string(root->val);
        res.push_back(path);
        return ;
    }

    path+="->"+to_string(root->val);
    dfs(root->left, res, path);
    dfs(root->right, res, path);
}
vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> res;
    string path = to_string(root->val);

    if(root->left==NULL && root->right==NULL){
        res.push_back(path);
    }

    dfs(root->left, res, path);
    dfs(root->right, res, path);

    return res;
}

int main(){
    return 0;
}