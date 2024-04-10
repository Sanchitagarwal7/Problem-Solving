#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    TrieNode* children[26];
    int minWordIndex;

    TrieNode(int index){
        for(int i = 0; i<26; i++){
            this->children[i] = NULL;
        }
        this->minWordIndex = index;
    }

    TrieNode* getChar(char &ch){
        return this->children[ch-'a'];
    }

    void setChar(char &ch, TrieNode* node){
        this->children[ch-'a'] = node;
    }
};


class Trie {
public:
TrieNode* root;
    Trie() {
        root = new TrieNode(-1);
    }
    
    void insert(string &word, int &ind, vector<string>& wordsContainer) {
        int n = word.length();
        TrieNode* node = root;

        for(int i = n-1; i>=0; i--){
            if(node->getChar(word[i])==NULL){
                TrieNode* newNode = new TrieNode(ind);
                node->setChar(word[i], newNode);
            }
            node = node->getChar(word[i]);

            //compare the existing index's word length that shares the same suffix as current word's length
            if(n < wordsContainer[node->minWordIndex].length()){
                node->minWordIndex = ind;   //if current word is small then update the index in that trie node
            }
        }
    }

    int search(string &suffix){
        int n = suffix.length();
        TrieNode* node = root;

        for(int i = n-1; i>=0; i--){
            if(node->getChar(suffix[i])==NULL){
                break; //itna hi longest common suffix tha
            }
            node = node->getChar(suffix[i]); //keep continuing
        }
        //return kro last node ka minWordIndex
        return node->minWordIndex;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int n = wordsContainer.size();
        int m = wordsQuery.size();

        Trie* t = new Trie();

        int miniIndex = 0;

        //first insert all words
        for(int i = 0; i<n; i++){
            string word = wordsContainer[i];
            int l = word.length();

            t->insert(word, i, wordsContainer);

            if(wordsContainer[miniIndex].length() > l){ //get index of word whose length is minimum
                miniIndex = i;
            }
        }

        //now search the suffix
        //where suffix ends get the index stored at that node, that will be our shortest string with longest common suffix
        vector<int> res(m);        
        for(int i = 0; i<m; i++){
            res[i] = t->search(wordsQuery[i]);
            if(res[i]==-1){ //agar esa suffix h jo kisika suffix nahi h toh -1 return hoga
                res[i] = miniIndex; //if thats the case then replace that with index of string that is smallest
            }
        }
        return res;
    }
};

int main(){
    return 0;
}