#include<bits/stdc++.h>
using namespace std;

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int n = preorder.size();
    //first element of preorder is guaranteed to be root
    TreeNode* root = new TreeNode(preorder[0]);
    stack<TreeNode*> st;
    st.push(root);

    for(int i = 1; i<n; i++){
        TreeNode* node = new TreeNode(preorder[i]);
        if(st.top()->val > node->val){
            //smaller value to the left
            st.top()->left = node;
            //push this node in stack
            st.push(node);
        }else{
            //we have higher value
            TreeNode* prev = NULL;
            while(!st.empty() && st.top()->val < node->val){
                prev = st.top();
                st.pop();
            }
            prev->right = node;
            st.push(node);
        }
    }
    return root;
}

int main(){
    return 0;
}