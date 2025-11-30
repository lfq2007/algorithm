#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int>f(n);
        f[0] = nums[0];
        f[1] = max(nums[0],nums[1]);//注意这个不是单纯nums[1]
        for(int i = 2; i < n; i++){
            f[i] = max(f[i - 2] + nums[i],f[i - 1]);
        }
        return f[n - 1];//这里代表的是前n个最大值，直接返回n - 1即可，不用返回两个
    }
};