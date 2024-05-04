#include<bits/stdc++.h>
using namespace std;

//MEMOIZATION
long long solve(vector<vector<int>>& questions, int index, int &n, vector<long long> &dp){
    //base case
    if(index>=n) return 0;
    if(dp[index]!=-1) return dp[index];

    //two choices do the quesion, or not do
    long long not_do = 0+solve(questions, index+1, n, dp);

    long long do_ques = 0; //can do, then skip to next do-able question from current index(question), since we can only solve inorder
    do_ques += questions[index][0] + solve(questions, index+questions[index][1]+1, n, dp);

    return dp[index] = max(not_do, do_ques);
}
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();

    vector<long long> dp(n, -1);
    int index = 0;

    return solve(questions, index, n, dp);
}

//TABULATION
long long mostPoints(vector<vector<int>>& questions) {
    int n = questions.size();

    vector<long long> dp(n+1, 0);

    for(int i = n-1; i>=0; i--){
        //two choices do the quesion, or not do
        long long not_do = 0+dp[i+1];

        long long do_ques = 0; //can do, then skip to next do-able question from current index(question), since we can only solve inorder

        if(i + questions[i][1]+1 >= n){ //handle out of bound
            do_ques += questions[i][0] + 0;
        }else{
            do_ques += questions[i][0] + dp[i + questions[i][1]+1];
        }

        dp[i] = max(not_do, do_ques);
    }

    return dp[0];
}

int main(){
    return 0;
}