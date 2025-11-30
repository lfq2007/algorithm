//给定一个整数数组 nums 和一个整数目标值 target，
//请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

//你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

//你可以按任意顺序返回答案。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                return {i,m[nums[i]]};
            }
            else{
                m[target - nums[i]] = i;
            }
        }
        return {};
    }
};