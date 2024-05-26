#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION (MLE)
    // int solve(vector<int>& cardPoints, int i, int j, int taken, int k, vector<vector<int>>& dp){
    //     //base ase
    //     if(taken==k || i>j) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int front = cardPoints[i]+solve(cardPoints, i+1, j, taken+1, k, dp);
    //     int back = cardPoints[j]+solve(cardPoints, i, j-1, taken+1, k, dp);

    //     return dp[i][j] = max(front, back);
    // }
    // int maxScore(vector<int>& cardPoints, int k) {
    //     int n = cardPoints.size();
    //     int i = 0;
    //     int j = n-1;

    //     int taken = 0;

    //     vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    //     return solve(cardPoints, i, j, taken, k, dp);
    // }

//TABULATION
int maxScore(vector<int>& cardPoints, int k) {
    int n=cardPoints.size();

    vector<int> front(k+1); //+1 for front = 0, back = k, vice versa
    vector<int> back(k+1);

    front[0] = 0;
    for(int i=0;i<k;i++){
        front[i+1] = front[i]+cardPoints[i];
    }

    back[0] = 0;
    for(int i=0;i<k;i++){
        back[i+1] = back[i] + cardPoints[n-i-1];
    }

    int maxi = 0;

    for(int i=0;i<=k; i++){
        int sum = front[i] + back[k-i]; //from frnot and back both
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main(){
    return 0;
}