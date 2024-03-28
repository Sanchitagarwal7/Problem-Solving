#include<bits/stdc++.h>
using namespace std;

bool findPath(TreeNode* root, string &path, int &target){
    //base case
    if(root==NULL) return false;
    if(root->val == target)
    {
        return true;
    }

    path+="L";
    if(findPath(root->left, path, target)){
        return true;
    }
    path.pop_back();

    path+="R";
    if(findPath(root->right, path, target)){
        return true;
    }
    path.pop_back();
    return false;
}

string getDirections(TreeNode* root, int startValue, int destValue) {
    string pathToStartNode = "", pathToDestNode = "";

    findPath(root, pathToStartNode, startValue);
    findPath(root, pathToDestNode, destValue);
    // cout << pathToStartNode << endl;
    // cout << pathToDestNode << endl;

    //got paths from root to targets
    //now to remove common part from root to lca, we can only remove from back so reverse both paths
    reverse(pathToStartNode.begin(), pathToStartNode.end());
    reverse(pathToDestNode.begin(), pathToDestNode.end());

    //remove common parts
    int i = pathToStartNode.length()-1, j = pathToDestNode.length()-1;
    while(i>=0 && j>=0 && pathToStartNode[i]==pathToDestNode[j]){
        pathToStartNode.pop_back();
        pathToDestNode.pop_back();
        i--;
        j--;
    }

    //if there still exists pathToStartNode that means we need to go 'U' direction (dry run)
    //since we need to go from st to dest
    for(int i = 0; i<pathToStartNode.length(); i++){
        pathToStartNode[i] = 'U';
    }

    //reverse path of dest node to undo previous reverse operation
    reverse(pathToDestNode.begin(), pathToDestNode.end());

    return pathToStartNode + pathToDestNode; //join
}

int main(){
    return 0;
}