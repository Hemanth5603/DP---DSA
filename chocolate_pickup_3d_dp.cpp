#include <bits/stdc++.h> 
using namespace std;
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) return -1e8;

    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    if(i == r-1){ 
        if(j1 == j2) return grid[i][j1];
        else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= 1;dj1++){
        for(int dj2 = -1;dj2 <= 1;dj2++){
            int value = 0;
            if(j1==j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += solve(i+1, dj1+j1, dj2+j2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solve(0, 0, c-1, r, c, grid, dp);
    
}

// Tabulation Code

// int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
//     vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
//     for(int j1 = 0;j1<m;j1++){
//         for(int j2 = 0;j2<m;j2++){
//             if(j1==j2) dp[n-1][j1][j2] = grid[n-1][j1];
//             else dp[n-1][j1][j2] = grid[n-1][j1] + grid[n-1][j2];
//         }
//     }

//     for(int i = n-2;i>=0;i--){
//         for(int j1 = 0;j1< m;j1++){
//             for(int j2 = 0;j2 < m;j2++){
//                 int maxi = -1e8;
//                 for(int dj1 = -1; dj1 <= 1;dj1++){
//                     for(int dj2 = -1;dj2 <= 1;dj2++){
//                         int value = 0;
//                         if(j1==j2) value = grid[i][j1];
//                         else value = grid[i][j1] + grid[i][j2];
//                         if(j1+dj1 >= 0 && j1+dj1 < m && dj2+j2 > 0 && dj2+j2 < m){
//                             value += dp[i+1][dj1+j1][dj2+j2];
//                         }else{ 
//                             value += -1e8;
//                         }
                        
//                         maxi = max(maxi, value);
//                     }
//                 }
//                 dp[i][j1][j2] = maxi;
//             }

//         }
//     }
//     return dp[0][0][m-1]; 
// }