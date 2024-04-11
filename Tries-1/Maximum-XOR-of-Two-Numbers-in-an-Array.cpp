#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        TrieNode* children[2];

        TrieNode(){
            for(int i = 0; i<2; i++){
                children[i] = NULL;
            }
        }

        TrieNode* getChar(int &bit){
            return children[bit];
        }

        void putChar(int &bit, TrieNode* &node){
            children[bit] = node;
        }
};

class Trie{
    public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(string &binary){
        TrieNode* node = root;

        for(int i = 0; i<32; i++){
            int bit = binary[i]-'0';

            if(node->getChar(bit)==NULL){
                TrieNode* newNode = new TrieNode();
                node->putChar(bit, newNode);
            }
            node = node->getChar(bit);
        }
    }

    void search(string &bin, int &maxi){
        TrieNode* node = root;

        int ans = 0;

        for(int i = 0; i<32; i++){
            int bit = bin[i]-'0';
            int altBit = abs(bit-1);

            //search if correspoding alternate exists becoz xor gives 1 when different bits, we need to maximize
            if(node->getChar(altBit)!=NULL){
                ans += (1<<(32-i-1)); //multiply with the power of two, 2^(ith bit from left) //most significant
                
                node = node->getChar(altBit); //got to that alternate bit
            }else{
                node = node->getChar(bit); //got to that bit only, we have no choice
            }
        }
        
        maxi = max(maxi, ans);
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int n = nums.size();

        Trie* t = new Trie();

        for(int i = 0; i<n; i++){
            string binaryFormat="";
            for(int j = 0; j<32; j++){
                if(nums[i]&(1<<j)){
                    binaryFormat += "1";
                }else{
                    binaryFormat += "0";
                }
            }
            reverse(binaryFormat.begin(), binaryFormat.end());
            t->insert(binaryFormat);
        }

        int maxi = -1e9;
        for(int i = 0; i<n; i++){
            string binaryFormat="";
            for(int j = 0; j<32; j++){
                if(nums[i]&(1<<j)){
                    binaryFormat += "1";
                }else{
                    binaryFormat += "0";
                }
            }
            reverse(binaryFormat.begin(), binaryFormat.end());
            t->search(binaryFormat, maxi);
        }

        return maxi;
    }
};



int main(){
    return 0;
}