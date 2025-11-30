//给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
//请你从 nums 中找出并返回总和为 target 的元素组合的个数。
//请注意，顺序不同的序列被视作不同的组合
//题目数据保证答案符合 32 位整数范围。

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int>f(target + 1);
        f[0] = 1;
        for(int i = 0; i <= target; i++ ){
            for(int x : nums){
                if(i + x <= target){
                    f[i + x] += f[i];
                }//或者写成if(i >= x) f[i] += f[i - x];
            }
        }
        return f[target];
    }
};