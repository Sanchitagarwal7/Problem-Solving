#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        TrieNode* children[26];
        bool isEnd;

        TrieNode(){
            for(int i = 0; i<26; i++){
                this->children[i] = NULL;
            }
            this->isEnd = false;
        }

        TrieNode* getChar(char &ch){
            return this->children[ch-'a'];
        }

        void putChar(char &ch, TrieNode* &node){
            this->children[ch-'a'] = node;
        }

        void setEnd(){
            this->isEnd = true;
        }

        bool getEnd(){
            return this->isEnd;
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
                if(node->getChar(word[i])==NULL){
                    TrieNode* newNode = new TrieNode();
                    node->putChar(word[i], newNode);
                }
                node = node->getChar(word[i]);
            }
            node->setEnd();
        }

        string search(string &word){
            TrieNode* node = root;

            string s = ""; //word to be replaced with

            for(int i = 0; i<word.length(); i++){
                if(node->getChar(word[i])!=NULL){
                    s+=word[i]; //apend in word string
                }else{
                    //wrna word ko hi return krdo
                    s = word;
                    break;
                }

                node = node->getChar(word[i]);

                if(node->getEnd()==true){ //wo letter agr dictionary mein h toh return krdo
                    return s;
                }
            }
            return s;
        }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence){
        int n = dictionary.size();
        int m = sentence.length();

        Trie* t = new Trie();

        //insert all words of dictionary in trie
        for(int i = 0; i<n; i++){
            t->insert(dictionary[i]);
        }

        string res = "";
        string singleWord = "";

        for(int i = 0; i<m; i++){
            char ch = sentence[i];
            if(ch==' '){
                //word completed so search in trie to get a possible root
                res += t->search(singleWord) + " ";
                singleWord = ""; //reset for next word
            }else{
                singleWord+=ch;
            }
        }
        //last word need to be checked
        res += t->search(singleWord);
        
        return res;
    }
};

int main(){
    return 0;
}