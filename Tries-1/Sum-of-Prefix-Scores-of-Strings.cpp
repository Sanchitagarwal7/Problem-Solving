#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isEnd;
        int prefixCount;

        TrieNode(){
            this->isEnd = false;
            this->prefixCount = 0; //prefixCount
        }

        TrieNode* getChar(char &ch){
            return this->children[ch];
        }

        void putChar(char &ch, TrieNode* &node){
            this->children[ch] = node;
        }

        bool getEnd(){
            return this->isEnd;
        }

        void setEnd(){
            this->isEnd = true;
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }

        void insert(string &word){
            TrieNode* node = root;
            for(int i = 0; i<word.length(); i++){
                if(!node->getChar(word[i])){
                    //insert character
                    TrieNode* newNode = new TrieNode();
                    node->putChar(word[i], newNode);
                }
                node = node->getChar(word[i]);
                node->prefixCount += 1;
            }
            node->setEnd();
        }

        long long search(string &word){
            long long sum = 0;

            TrieNode* node = root;
            for(int i = 0; i<word.length(); i++){
                node = node->getChar(word[i]);
                sum += node->prefixCount; //sum all prefixCount of the word
            }
            return sum;
        }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();

        Trie* t = new Trie();

        //insert all words in trie
        for(int i = 0; i<n; i++){
            t->insert(words[i]);
        }

        vector<int> res(n);
        //search all words
        for(int i = 0; i<n; i++){
            res[i] = t->search(words[i]);
        }
        return res;
    }
};

int main(){
    return 0;
}