#include<bits/stdc++.h>
using namespace std;

TreeNode* generateTree(vector<int>& nums, int low, int high){
        //base case
        if(high < low){
            return NULL;
        }

        //make mid+1 root
        int mid = low+(high-low)/2;
        TreeNode* root = new TreeNode(nums[mid]);

        //get its children
        root->left = generateTree(nums, low, mid-1);
        root->right = generateTree(nums, mid+1, high);

        return root;
    }

TreeNode* sortedArrayToBST(vector<int>& nums) {
    //make a skew bst but problem said to make it into a height-balanced
    return generateTree(nums, 0, nums.size()-1);
}

int main(){
    return 0;
}