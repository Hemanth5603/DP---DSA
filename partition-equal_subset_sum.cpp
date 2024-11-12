#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int dp[205][20005];
    int fn(vector<int>&a, int i,int sum){
        if(sum==0)return 1;
        if(i==a.size())return 0;
        int ans=0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        if(sum>=a[i])ans|=fn(a,i+1,sum-a[i]);
                     ans|=fn(a,i+1,sum);
        return dp[i][sum]=ans;
    }
    bool canPartition(vector<int>& a) {
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<a.size();i++)sum+=a[i];
        // cout<<sum<<endl;
        if(sum%2)return 0;
        return fn(a,0,sum/2);
    }
};