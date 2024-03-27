#include<bits/stdc++.h>
using namespace std;

long long count = 0;
void dfs(TreeNode* root, long long target){
    //base case
    if(root==NULL){
        return ;
    }
    if(target==root->val){
        count++;
    }

    dfs(root->left, target-root->val);
    dfs(root->right, target-root->val);
}
int pathSum(TreeNode* root, int targetSum) {
    if(root==NULL) return 0;

    dfs(root, targetSum);

    pathSum(root->left, targetSum);
    pathSum(root->right, targetSum);

    return count;
}

int main(){
    return 0;
}