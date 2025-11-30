#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int s = accumulate(nums.begin(),nums.end(),0);
        if(s % 2 == 1)return false;
        s /= 2;
        int n = nums.size();
        if(s < nums[0]) return false;
        vector<vector<int>>f(n + 1,vector<int>(s + 1));//f[i][j]表示前i个数能否到达s
        f[0][0] = 1;
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < s + 1; j++){
                //不选
                f[i][j] = f[i - 1][j];
                //选
                if(nums[i - 1] <= j ){
                    f[i][j] = f[i - 1][j - nums[i - 1]] || f[i - 1][j];
                } 
            }
        }
        return f[n][s];
    }
};