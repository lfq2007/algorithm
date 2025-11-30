#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int simplerob(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return nums[0];
        if(n == 2) return max(nums[0],nums[1]);
        vector<int>f(n);
        f[0] = nums[0];
        f[1] = max(nums[0],nums[1]);
        for(int i = 2; i < n; i++){
            f[i] = max(f[i - 2] + nums[i],f[i - 1]);
        }
        return f[n - 1];
    }
//这个题的难点在于环形的处理，其实只要分为两部分就行了，反正1和n不能一起偷
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int>a(nums.begin(),nums.end() - 1);
        vector<int>b(nums.begin() + 1,nums.end());
        return max(simplerob(a),simplerob(b));
    }
};