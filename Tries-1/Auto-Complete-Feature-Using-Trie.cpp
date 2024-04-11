#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    bool isEnd;
    vector<string> commonNames;

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
            node->commonNames.push_back(word); //push words that have same prefix till node
        }
        node->setEnd();
    }
    
    void print(string word) {
        TrieNode* node = root;
        for(int i = 0; i<word.length(); i++){
            if(node->getChar(word[i])==NULL){
                cout << "No Suggestions With This Prefix" << endl;
                break;
            }
            node = node->getChar(word[i]);
        }

        for(int i = 0; i<node->commonNames.size(); i++){
            cout << node->commonNames[i] << endl;
        }
    }
};

int main()
{
    Trie* t = new Trie();

    t->insert("rat");
    t->insert("rattled");
    t->insert("dat");
    t->insert("cattle");
    t->insert("carnage");
    t->insert("c");
    t->insert("dog");
    t->insert("doggy");
    t->insert("doe");

    t->print("d");
 
    return 0;
}