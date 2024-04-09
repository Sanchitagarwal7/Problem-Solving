#include<bits/stdc++.h>
using namespace std;

bool solve(TreeNode* root, int k, unordered_map<int, int> &mp){
    //base case
    if(root==NULL){
        return false;
    }
    if(mp.find(k-root->val)!=mp.end()){
        return true;
    }

    mp[root->val]++;

    return solve(root->right, k, mp) || solve(root->left, k, mp);
}

bool findTarget(TreeNode* root, int k) {
    unordered_map<int, int> mp;
    return solve(root, k, mp);
}

int main(){
    return 0;
}