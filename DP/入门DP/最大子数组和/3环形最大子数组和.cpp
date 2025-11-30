#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int s_max = INT_MIN / 2;
        int s_min = INT_MAX / 2;
        int f_max = INT_MIN / 2;
        int f_min = INT_MAX / 2;
        int s = 0;
        for(int num: nums){
            s += num;
            f_max = max(0,f_max) + num;
            s_max = max(s_max,f_max);
            f_min = min(0,f_min) + num;
            s_min = min(s_min,f_min);
        }
        return s_max < 0 ? s_max : max(s_max,s - s_min);
    }
};
//注意负值的处理
//跨过的部分用两个解需要考虑长度，总的减剩下的也是一种方法