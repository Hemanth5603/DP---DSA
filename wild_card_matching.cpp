#include<bits/stdc++.h>

using namespace std;

//understand the question first, Understand the recurance first

class Solution {
public:

    int solve(int i, int j, string p, string s, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >=0) return false;
       
        if(j < 0 && i >=0){
            for(int ii = 0;ii<=i;ii++){
                if(p[ii] != '*') return false;
            }
            return true;
        }
         if(dp[i][j] != -1) return dp[i][j];

        if(p[i] == s[j] || p[i] == '?'){
            return dp[i][j] = solve(i-1, j-1, p, s, dp);
        }
        if(p[i] == '*'){
            return dp[i][j] = solve(i-1, j, p, s, dp) | solve(i, j-1, p, s, dp);
        }

        return dp[i][j] = false;
    }



    // Tabulation 
    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,false));
        dp[0][0] = true;

        for(int j=1;j<=m;j++){
            dp[0][j] = false;
        }

        for(int i=1;i<=n;i++){
            bool flag = true;
            for(int ii = 1;ii<=i;ii++){
                if(p[ii-1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[i-1] == s[j-1] || p[i-1] == '?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1] == '*'){
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }

                else dp[i][j] = false;
            }
        }



        return dp[n][m];
    }
};