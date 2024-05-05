#include<bits/stdc++.h>
using namespace std;

int calculateMinimumHP(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    vector<vector<int>> dp(n, vector<int>(m, 1e9));

    //at n-1, m-1:
    //if mat[n-1][m-1] > 0 then, 1 otherwise -mat[n-1][m-1]+1;

    //at other cells:
    //if mat[i][j] > 0 then : max(1, min(dp[i+1][j], dp[i][j+1])-mat[i][j])
    //if mat[i][j] < 0 then: min(dp[i+1][j], dp[i][j+1])-mat[i][j]

    for(int i = n-1; i>=0; i--){
        for(int j = m-1; j>=0; j--){

            if(i==n-1 && j==m-1){
                //explicitly base case for n-1, m-1;
                dp[i][j] = (mat[i][j]<0) ? abs(mat[i][j])+1 : 1;
            }

            int minHealth = 1e9;
            //right
            if(j+1<m){
                minHealth = dp[i][j+1];
            }
            //down
            if(i+1<n){
                minHealth = min(minHealth, dp[i+1][j]);
            }
            //from formula
            minHealth = minHealth - mat[i][j];

            if(mat[i][j]>0){ //again from formula
                minHealth = max(1, minHealth);
            }

            dp[i][j] = min(dp[i][j], minHealth); //to get min health for this cell
        }
    }

    return dp[0][0];
}

int main(){
    return 0;
}