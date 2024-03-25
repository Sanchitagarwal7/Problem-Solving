#include<bits/stdc++.h>
using namespace std;
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";

        queue<TreeNode*> q;
        q.push(root);

        string tree = "";
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i<size; i++){
                auto temp = q.front(); q.pop();

                if(temp==NULL){
                    tree+=">N";
                    continue;
                }else{
                    if(tree.length()==0) tree+=to_string(temp->val);
                    else
                        tree+=">"+to_string(temp->val);
                }

                if(temp->left){
                    q.push(temp->left);
                }else{
                    q.push(NULL);
                }

                if(temp->right){
                    q.push(temp->right);
                }else{
                    q.push(NULL);
                }
            }
        }

        return tree;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="") return NULL;

        int n = data.length();

        string val;

        int i = 0;
        while(i<n && data[i]!='>'){
            val+=data[i++];
        }
        i++;
        TreeNode* root = new TreeNode(stoi(val));
        val="";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* parent = q.front(); q.pop();

            while(i<n && data[i]!='>'){
                val+=data[i++];
            }
            i++;

            if(val=="N"){
                parent->left = NULL;
            }else{
                parent->left = new TreeNode(stoi(val));
                q.push(parent->left);
            }
            val="";

            while(i<n && data[i]!='>'){
                val+=data[i++];
            }
            i++;

            if(val=="N"){
                parent->right = NULL;
            }else{
                parent->right = new TreeNode(stoi(val));
                q.push(parent->right);
            }
            val="";
        }

        return root;
    }
int main(){
    return 0;
}