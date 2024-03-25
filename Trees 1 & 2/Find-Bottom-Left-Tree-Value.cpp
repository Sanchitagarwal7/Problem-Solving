#include<bits/stdc++.h>
using namespace std;

int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    int ans;

    while(!q.empty()){
        auto size = q.size();

        vector<int> res;

        for(int i = 0; i<size; i++){
            auto temp = q.front(); q.pop();

            res.push_back(temp->val);

            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
        }
        ans = res[0];
    }
    return ans;
}

int main(){
    return 0;
}