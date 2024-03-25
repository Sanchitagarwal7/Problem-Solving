#include<bits/stdc++.h>
using namespace std;

bool isSameTree(TreeNode* p, TreeNode* q) {
    //traverse both trees in same order
    //lets do preorder -> NLR
    //base case
    if(p==NULL && q==NULL){
        return true;
    }

    if(p==NULL && q!=NULL || q==NULL && p!=NULL || p->val != q->val){
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    return 0;
}