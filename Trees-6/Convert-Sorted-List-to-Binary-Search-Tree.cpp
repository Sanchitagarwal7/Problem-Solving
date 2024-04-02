#include<bits/stdc++.h>
using namespace std;

TreeNode* solve(ListNode* low, ListNode* high){
    //base case
    if(low==high){
        return NULL;
    }

    ListNode* slow = low;
    ListNode* fast = low;

    while(fast->next!=high && fast->next->next!=high){
        slow = slow->next;
        fast = fast->next->next;
    }

    TreeNode* root = new TreeNode(slow->val);

    root->left = solve(low, slow);
    root->right = solve(slow->next, high);

    return root;
}
TreeNode* sortedListToBST(ListNode* head) {
    ListNode* low = head;
    ListNode* high = NULL;
    //same as bst from inorder traversal
    return solve(low, high);
}

int main(){
    return 0;
}