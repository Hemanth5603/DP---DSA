#include<bits/stdc++.h>

using namespace std;

class Solution {
public:

    int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i < 0) return j+1; // if the stirng exausts then we require j +1 replace to make the resultant solution
        if(j < 0) return i+1;

        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]) return solve(i-1, j-1, s1, s2, dp);


        // insert call, delete call, replace call 

        return dp[i][j] = 1 + min(solve(i-1, j, s1, s2, dp), min(solve(i, j-1, s1, s2, dp),
            solve(i-1, j-1, s1, s2, dp)));
    }



        
    int minDistance(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }


        return dp[n][m];
    }
};