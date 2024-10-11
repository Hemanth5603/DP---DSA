#include<bits/stdc++.h>

using namespace std;
class Solution {
public:

    int solve(int ind, int buy,int k, vector<int> prices, int n,vector<vector<vector<int>>> &dp){
        if(ind == n || k == 0) return 0;

        if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        if(buy == 1){
            return dp[ind][buy][k] = max(-prices[ind] + solve(ind + 1, 0,k, prices, n, dp), 
                0 + solve(ind + 1, 1, k, prices, n, dp));
        }

        return dp[ind][buy][k] = max(prices[ind] + solve(ind + 1, 1, k-1, prices, n, dp),
                0 + solve(ind + 1, 0, k, prices, n, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int ind = n-1;ind >=0;ind--){
            for(int buy =0; buy <=1; buy++){
                for(int t = 1;t <= k;t++){
                    if(buy == 1){
                        dp[ind][buy][t] = max(-prices[ind] + dp[ind + 1][0][t], 
                            0 + dp[ind + 1][1][t]);
                    }
                    else{
                        dp[ind][buy][t] = max(prices[ind] + dp[ind + 1][1][t-1],
                            0 + dp[ind + 1][0][t]);
                        }
                    }
                }    
            }
        return dp[0][1][k];
    }
};