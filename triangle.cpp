#include<bits/stdc++.h>

using namespace std;
class Solution {
public:

    int solve(int i, int j, vector<vector<int>> &triangle,int n,int m,                   vector<vector<int>> &dp){
        if(i == n-1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int dw = triangle[i][j] + solve(i+1, j, triangle, n, m, dp);
        int dg = triangle[i][j] + solve(i+1, j+1, triangle, n, m, dp);

        return dp[i][j] = min(dw, dg);
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[0].size(); 
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, 0, triangle, n, m, dp);
    }
};