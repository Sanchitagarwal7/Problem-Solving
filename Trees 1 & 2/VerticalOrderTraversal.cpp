#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, map<int, multiset<int>>> mp; //y,x, [nodes], ordered to store sorted y
    queue<pair<TreeNode* ,pair<int, int>>> q; //every nodes x and y
    q.push({root, {0, 0}});

    vector<vector<int>> ans;

    while(!q.empty()){
        auto temp = q.front(); q.pop();

        TreeNode* node = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;

        mp[y][x].insert(node->val);

        if(node->left){
            q.push({node->left, {x+1, y-1}});
        }
        if(node->right){
            q.push({node->right, {x+1, y+1}});
        }
    }

    for(auto it: mp){
        vector<int> temp;
        for(auto jt: it.second){
            temp.insert(temp.end(), jt.second.begin(), jt.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    return 0;
}