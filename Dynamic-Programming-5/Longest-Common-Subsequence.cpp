#include<bits/stdc++.h>
using namespace std;


/*Memoization*/
class Solution {
public:
    int findCommon(string &text1, string &text2, int index1, int index2, vector<vector<int>> &dp)
    {
        //base case
        if(index1 < 0 || index2 < 0)
        {
            return 0;
        }
        if(dp[index1][index2]!=-1) return dp[index1][index2];

        //match
        if(text1[index1] == text2[index2])
        {
            return dp[index1][index2] = 1 + findCommon(text1, text2, index1-1, index2-1, dp);
        }

        //do not match

        return dp[index1][index2] = max(findCommon(text1, text2, index1, index2-1, dp), findCommon(text1, text2, index1-1, index2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int index1 = text1.length()-1;
        int index2 = text2.length()-1;

        vector<vector<int>> dp(index1+1, vector<int>(index2+1, -1));

        return findCommon(text1, text2, index1, index2, dp);
    }
};

/*Tabulation*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for(int i = 0; i<=n; i++)
        {
            dp[i][0] = 0;
        }
        for(int j = 0; j<=m; j++)
        {
            dp[0][j] = 0;
        }

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                //match
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } //do not match
                else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);   
                }
            }
        }

        return dp[n][m];
    }
};


/*Space Optimisation*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> prev(m+1, 0);
        vector<int> curr(m+1, 0);

        for(int j = 0; j<=m; j++)
        {
            prev[j] = 0;
        }

        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                //match
                if(text1[i-1] == text2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                } //do not match
                else {
                    curr[j] = max(curr[j-1], prev[j]);   
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};

int main(){
    return 0;
}