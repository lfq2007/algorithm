//给你一个长度为 n 的整数数组 nums 。对于 每个 下标 i（0 <= i < n），
//定义对应的子数组 nums[start ... i]（start = max(0, i - nums[i])）。

//返回为数组中每个下标定义的子数组中所有元素的总和。

//子数组 是数组中的一个连续、非空 的元素序列。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n = nums.size();
        vector<int>f(n + 1,0);
        int ans = 0;
        for(int i = 0; i < n; i++){
            f[i + 1] = f[i] + nums[i];//定义前缀和数组，f[i]代表前i个之和，注意对应 
        }
        for(int i = 0; i < n; i++){
            int start = max(0,i - nums[i]);
            ans += f[i + 1] - f[start];
        }
        return ans;
    }
};
//回头看像是一个很简单的题11.3