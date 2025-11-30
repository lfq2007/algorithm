#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums1,vector<int>& nums2) {
        int n = nums1.size();
        int max_ans = 0;
        int f_max = INT_MIN;
        int s = 0;
        for(int i = 0; i < n; i++){
            s += nums1[i];
            f_max = max(f_max,0) + nums2[i] - nums1[i];
            max_ans = max(max_ans, f_max);
        }
        return s + max_ans;
        
    }
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        //首先，如果对应位置一个永远大于另一个，就不交换
        //思考：尽可能大的n个数，但是又有连续的限制，可以从sum ，最大子数组入手
        //找的是最大的子数组差值
        //思路1:两数组作差，最大子数组绝对值，替换到-->替换后返回两个sum的最大值
        int n = nums1.size();
        if(n == 1) return max(nums1[0],nums2[0]);
        //vector<int>diff(n);
        //for(int i = 0; i < n; i++){
          //  diff[i] = nums1[i] - nums2[i];
        //}
        //这里我们计算后发现就是s - diff
        //不用管是哪个，直接取两者最大即可
        //return(maxSubArray(diff[i]))这里再次发现可以把差也写到函数里

        return max(maxSubArray(nums1,nums2),maxSubArray(nums2,nums1));
    }
};