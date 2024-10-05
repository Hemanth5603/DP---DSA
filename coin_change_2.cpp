#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long solve(int ind, int t, vector<int> &coins,vector<vector<int>> &dp){
        if(ind == 0){
            return (t % coins[0] ==0);
        }

        if(dp[ind][t] != -1) return dp[ind][t];
        long nottake = solve(ind-1, t, coins, dp);
        long take = 0;

        if(coins[ind] <= t){
            take = solve(ind, t - coins[ind], coins, dp);
        }

        return dp[ind][t] = take + nottake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};