#include<bits/stdc++.h>
using namespace std;

/*MEMOIZATION*/
// int solve(string &word1, string &word2, int idx1, int idx2, int &len1, int &len2, vector<vector<int>> &dp){
//     //base case
//     if(idx1==0 && idx2==0) return 0;
//     if(idx1==0) return idx2;
//     if(idx2==0) return idx1;
//     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];

//     if(word1[idx1-1]==word2[idx2-1]){
//         return dp[idx1][idx2] = solve(word1, word2, idx1-1, idx2-1, len1, len2, dp);
//     }

//     int insertCh = 1+solve(word1, word2, idx1, idx2-1, len1, len2, dp);
//     int delCh = 1+solve(word1, word2, idx1-1, idx2, len1, len2, dp);
//     int repCh = 1+solve(word1, word2, idx1-1, idx2-1, len1, len2, dp);

//     return dp[idx1][idx2] = min(insertCh, min(delCh, repCh));
// }

/*TABULATION*/
// int minDistance(string word1, string word2) {
//     int len1 = word1.length();
//     int len2 = word2.length();

//     int index1 = len1;
//     int index2 = len2;

//     vector<vector<int>> dp(len1+1, vector<int>(len2+1, -1));
//     for(int i = 0; i<=len1; i++){
//         dp[i][0] = i;
//     }
//     for(int j = 0; j<=len2; j++){
//         dp[0][j] = j;
//     }

//     for(int ind1 = 1; ind1<=len1; ind1++){
//         for(int ind2 = 1; ind2<=len2; ind2++){
//             if(word1[ind1-1]==word2[ind2-1]){
//                 dp[ind1][ind2] = dp[ind1-1][ind2-1];
//             }else{
//                 int insertCh = 1+dp[ind1][ind2-1];
//                 int delCh = 1+dp[ind1-1][ind2];
//                 int repCh = 1+dp[ind1-1][ind2-1];

//                 dp[ind1][ind2] = min(insertCh, min(delCh, repCh));
//             }
//         }
//     }
//     return dp[index1][index2];
// }

int minDistance(string word1, string word2) {
    int len1 = word1.length();
    int len2 = word2.length();

    int index1 = len1;
    int index2 = len2;

    vector<int> temp(len2+1, 0);

    for(int j = 0; j<=len2; j++){
        temp[j] = j;
    }

    for(int ind1 = 1; ind1<=len1; ind1++){
        
        vector<int> curr(len2+1, 0);
        curr[0] = ind1;
        
        for(int ind2 = 1; ind2<=len2; ind2++){
            if(word1[ind1-1]==word2[ind2-1]){
                curr[ind2] = temp[ind2-1];
            }else{
                int insertCh = 1+curr[ind2-1];
                int delCh = 1+temp[ind2];
                int repCh = 1+temp[ind2-1];

                curr[ind2] = min(insertCh, min(delCh, repCh));
            }
        }

        temp = curr;
    }

    return temp[index2];
}

int main(){
    return 0;
}