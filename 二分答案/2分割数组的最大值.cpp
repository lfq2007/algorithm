#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int>& nums, int ans) {
        int n = nums.size();
        int res = 0;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            tot += nums[i];
            if (nums[i] > ans) return INT_MAX;
            if (tot > ans) {
                tot = 0;
                i--;
                res++;
            }
        }
        return res + 1;//注意返回值是数组个数不是切分次数
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = accumulate(nums.begin(), nums.end(), 0);//注意这里可以为0
        while (l < r) {
            int mid = (r - l) / 2 + l;
            if (check(nums, mid) > k) {
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};

//分析：k越大，答案越小，单调，可以将固定k求答案转化成固定答案求k，这样把多种的分法转换为一旦大于最大值就要分割的固定操作

/*
给定一个非负整数数组 nums 和一个整数 k ，你需要将这个数组分成 k 个非空的连续子数组，使得这 k 个子数组各自和的最大值 最小。
返回分割后最小的和的最大值。
子数组 是数组中连续的部分。
示例 1：
输入：nums = [7,2,5,10,8], k = 2
输出：18
解释：
一共有四种方法将 nums 分割为 2 个子数组。 
其中最好的方式是将其分为 [7,2,5] 和 [10,8] 。
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。
*/