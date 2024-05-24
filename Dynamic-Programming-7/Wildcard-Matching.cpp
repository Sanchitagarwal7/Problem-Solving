#include<bits/stdc++.h>
using namespace std;

/* MEMOIZATION
bool solve(string &s, string &p, int m, int n, vector<vector<int>> &dp)
    {
        //base case
        if(m == 0 && n == 0) return true;
        if(m>=0 && n == 0) return false;
        if(m == 0 && n>=0){
            for(int i = 0; i<n; i++)
            {
                if(p[i]!='*')
                {
                    return false;
                }
            }
            return true;
        }

        if(dp[m][n]!=-1) return dp[m][n];


        //matching characters
        if(s[m-1] == p[n-1] || p[n-1] == '?')
        {
            return dp[m][n] = solve(s, p, m-1, n-1, dp);
        }
        //not matching characters
        else if(p[n-1] == '*')
        {
            return dp[m][n] = solve(s, p, m, n-1, dp) || solve(s, p, m-1, n, dp);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

        return solve(s, p , m, n, dp);
    }
*/
/* TABULATION
bool isAllStars(string &p, int index)
    {
        for(int j = 1; j<=index; j++)
        {
            if(p[j-1]!='*')
            {
                return false;
            }
        }
        return true;
    }
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        //base cases
        dp[0][0] = true;

        for(int i = 1; i<=m; i++)
        {
            dp[i][0] = false;
        }

        for(int i = 1; i<=n; i++)
        {
            dp[0][i] = isAllStars(p, i);
        }

        for(int ind1 = 1; ind1<=m; ind1++)
        {
            for(int ind2 = 1; ind2<=n; ind2++)
            {
                //matching characters
                if(s[ind1-1] == p[ind2-1] || p[ind2-1] == '?')
                {
                    dp[ind1][ind2] = dp[ind1-1][ind2-1];
                }
                //not matching characters
                else if(p[ind2-1] == '*')
                {
                    dp[ind1][ind2] = dp[ind1][ind2-1] || dp[ind1-1][ind2];
                }
                else
                {
                    dp[ind1][ind2] = false;
                }
            }
        }

        return dp[m][n];
    }
*/
bool isAllStars(string &p, int index)
{
    for(int j = 1; j<=index; j++)
    {
        if(p[j-1]!='*')
        {
            return false;
        }
    }
    return true;
}
bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();

    vector<bool> prev(n+1, false);
    vector<bool> curr(n+1, false);

    //base cases
    prev[0] = true;

    for(int i = 1; i<=n; i++)
    {
        prev[i] = isAllStars(p, i);
    }

    for(int ind1 = 1; ind1<=m; ind1++)
    {
        for(int ind2 = 1; ind2<=n; ind2++)
        {
            //matching characters
            if(s[ind1-1] == p[ind2-1] || p[ind2-1] == '?')
            {
                curr[ind2] = prev[ind2-1];
            }
            //not matching characters
            else if(p[ind2-1] == '*')
            {
                curr[ind2] = curr[ind2-1] || prev[ind2];
            }
            else
            {
                curr[ind2] = false;
            }
        }
        prev = curr;
    }

    return prev[n];
}

int main(){
return 0;
}