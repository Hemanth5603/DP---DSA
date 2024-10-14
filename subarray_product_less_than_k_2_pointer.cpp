#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int pro = 1, cnt = 0;
        int left = 0, right = 0;
        while(right < nums.size()){
            pro *= nums[right];
            while(pro >= k){
                pro /= nums[left];
                left++;
            }

            cnt += right - left +1;
            right++;
        }
        return cnt;
    }
};