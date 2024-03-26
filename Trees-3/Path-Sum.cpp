#include<bits/stdc++.h>
using namespace std;

bool solve(TreeNode* root, int targetSum, int sum)
{        
    //base case
    if(root==NULL)
    {
        return false;
    }
    sum+=root->val;
    if(root->left == NULL && root->right == NULL && sum == targetSum)
    {
        return true;
    }
    return solve(root->left, targetSum, sum)||solve(root->right, targetSum, sum);

}

bool hasPathSum(TreeNode* root, int targetSum) {
    int sum = 0; 

    return solve(root, targetSum, sum);
}

int main(){
    return 0;
}