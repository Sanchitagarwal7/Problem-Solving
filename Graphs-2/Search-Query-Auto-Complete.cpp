#include<bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    unordered_map<char, TrieNode*> children; //made a map instead of array to store characters beyond 'a-z'
    unordered_map<string, int> freq;
    
    TrieNode* getChar(char &ch){
        return this->children[ch];
    }
    
    void putChar(char &ch, TrieNode* node){
        this->children[ch] = node;
        return ;
    }
};

class AutoCompleteSystem {
public:
TrieNode* root;
TrieNode* pnode;
string inSen = "";

static bool cmp(pair<string, int>&a, pair<string, int>&b){
    if(a.second > b.second) return true; //large freq first
    if(a.second == b.second){   //if freq same
        return a.first < b.first;   //then lexographically smallest first
    }
    return false;
}

void insert(string sentence, int frequency){
    int n = sentence.length();
    TrieNode* node = root;
    
    for(int i = 0; i<n; i++){
        if(node->getChar(sentence[i])==NULL){
            TrieNode* newNode = new TrieNode();
            node->putChar(sentence[i], newNode);
        }
        node = node->getChar(sentence[i]);
        node->freq[sentence] += frequency;
    }
}

AutoCompleteSystem(vector<string>& sentences, vector<int>& times) {
    int n = sentences.size();
    root = new TrieNode();
    pnode=root;
    
    for(int i = 0; i<n; i++){
        int f = times[i];
        insert(sentences[i], f);
    }
}

vector<string> input(char c) {
    if(c=='#'){
        insert(inSen, 1);
        pnode = root;
        inSen = "";
        return {};
    }
    inSen+=c;
    if(pnode->children[c]==NULL){
        TrieNode* newNode = new TrieNode();
        pnode->putChar(c, newNode);
        pnode = pnode->getChar(c);
        return {};
    }
    pnode = pnode->getChar(c);
    
    vector<pair<string, int>> sugg;
    for(auto it: pnode->freq){
        sugg.push_back({it.first, it.second});
    }
    
    sort(sugg.begin(), sugg.end(), cmp);
    
    int k = sugg.size();
    vector<string> res;
    int minSugg = min(3, k);
    
    for(int i = 0; i<minSugg; i++){
        res.push_back(sugg[i].first);
    }
    
    return res;
}

int main(){
    return 0;
}