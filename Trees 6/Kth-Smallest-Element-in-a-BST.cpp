#include<bits/stdc++.h>
using namespace std;

void solve(TreeNode* root, int &k, int &ans){
    //base case
    if(root==NULL){
        return ;
    }
    //approach is whenever we get out of left recursion call we decrement k and check if 
    //k==0 then thats our element

    solve(root->left, k, ans);
    k--;
    if(k==0){
        ans = root->val;
        return ;
    }
    solve(root->right, k, ans);
}

int kthSmallest(TreeNode* root, int k) {
    int ans;
    solve(root, k, ans);
    return ans;
}

int main(){
    return 0;
}