#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        //设f[i] 为以nums[i]结尾的最大子数组和，
        //则f[i] = max(0,f[i - 1]) + nums[i],f[0] = nums[0];
        //返回值是max(f)
        int ans = INT_MIN;
        int f = 0;
        for(int x : nums){
            f = max(f,0) + x;
            ans = max(ans, f);
        }
        return ans;
    }
};
//下一题(leetcode)中重要的点只有iota(起始地址，终止地址，起始值)这个连续赋值函数