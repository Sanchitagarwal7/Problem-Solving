#include<bits/stdc++.h>
using namespace std;

class TrieNode {
    public:
        int num;
        TrieNode* children[2];

        TrieNode() {
            for (int i = 0; i < 2; i++) {
                this->children[i] = NULL;
            }
            this->num = 0;
        }
};

class Trie {
    public:
        TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(int num,int &log) {
        TrieNode* node = root;

        for (int i = log; i >= 0; i--) {
            bool bit = num & (1 << i);
            if (node->children[bit] == NULL) {
                TrieNode* newNode = new TrieNode();
                node->children[bit] = newNode;
            }
            node = node->children[bit];
            node->num += 1;
        }
    }

    int countPairsXORsmallerEqual(int num, int limit, int &log) {
        int pairs = 0;
        TrieNode* node = root;

        for (int i = log; i >= 0 && node; i--) {
            bool nbit = num&(1<<i);
            bool lbit = limit&(1<<i);

            if(lbit==0){
                if(node->children[nbit]){ //same bit xor=0
                    node = node->children[nbit];    //go to next node
                    continue;
                }else
                    //bda h
                    break;
            }

            if(node->children[nbit]){   //lbit == 1 and xor 0, mtlb chota h toh add krdo
                pairs += node->children[nbit]->num;
            }

            node = node->children[1-nbit];  //dusre path mein jaoo
        }

        return pairs;
    }
};

int countPairs(vector<int>& nums, int low, int high) {
        //calculate log for optimisation, otherwise we can take 32 also
        int log = 0;
        while((1<<log) <= 20000){
            log++;
        }
        
        Trie* t = new Trie();

        int count = 0;
        for (auto it : nums) {
            int count1 = t->countPairsXORsmallerEqual(it, high+1, log);
            int count2 = t->countPairsXORsmallerEqual(it, low, log);

            //(all xors < high+1) - (all xors < low) = (all xors >= low and < high+1)
            count += (count1 - count2);

            t->insert(it, log);
        }

        delete t;

        return count;
}

int main(){
    return 0;
}