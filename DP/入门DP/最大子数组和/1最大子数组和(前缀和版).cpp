#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //特殊情况处理
        int n = nums.size();
        if(n == 1) return nums[0];

        //前缀和数组
        vector<int>pre(n + 1);//pre[i]表示前i个数的和
        pre[0] = 0;
        for(int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + nums[i];
        }

        //买卖股票
        int minnum = INT_MAX  / 2;
        int ans = INT_MIN / 2;
        for(int i = 1; i <= n; i++){
            ans = max(ans,pre[i] - minnum);
            minnum = min(minnum,pre[i]);
            //注意这两句的顺序，因为要考虑至少一个数在里面
        }
        return ans;
    }
};
//另外，这里其实可以合并两个过程并且只维护一个前缀和