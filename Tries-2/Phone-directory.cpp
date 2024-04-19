#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    // vector<string> commonNames;

    TrieNode(){
        for(int i = 0; i<26; i++){
            this->children[i] = NULL;
        }
        this->isEnd = false;
    }

    TrieNode* getChar(char &ch){
        return this->children[ch-'a'];
    }

    void setChar(char &ch, TrieNode* node){
        this->children[ch-'a'] = node;
    }

    bool getEnd(){
        return this->isEnd;
    }

    void setEnd(){
        this->isEnd = true;
    }
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.length();
        TrieNode* node = root;

        for(int i = 0; i<n; i++){
            if(node->getChar(word[i])==NULL){
                TrieNode* newNode = new TrieNode();
                node->setChar(word[i], newNode);
            }
            node = node->getChar(word[i]);
            // node->commonNames.push_back(word); //push words that have same prefix till node
        }
        node->setEnd();
    }
    
    void dfs(TrieNode* node, string pref, vector<string>& sugg) {
        if(node == NULL) return;
        if(node->getEnd()) sugg.push_back(pref);

        for(int i = 0; i < 26; i++) {
            if(node->children[i] != NULL) {
                char ch = 'a' + i;
                dfs(node->children[i], pref + ch, sugg);
            }
        }
    }
    
    vector<string> print(string word) {
        int n = word.length();
        TrieNode* node = root;
        
        for(int i = 0; i<n; i++){
            if(node->getChar(word[i])==NULL){
                return {"0"};
            }
            node = node->getChar(word[i]);
        }
        
        vector<string> sugg;
        dfs(node, word, sugg);
        
        return sugg;
    }
};

vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    Trie* t = new Trie();
    
    for(int i = 0; i<n; i++){
        t->insert(contact[i]);
    }
    
    vector<vector<string>> res;
    string word = "";
    
    for(int i = 0; i<s.length(); i++){
        word+=s[i];
        res.push_back(t->print(word));
    }
    
    return res;
}

int main(){
    return 0;
}