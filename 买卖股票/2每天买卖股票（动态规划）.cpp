#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //特殊处理
        int n = prices.size();
        if(n <= 1) return 0;
        //定义状态
        vector<vector<int>>dp(n,vector<int>(2));//dp[i][0]不持股最大利润
        //dp[i][1]持股最大利润
        
        //初始化
        dp[0][0] = 0;dp[0][1] = -1 * prices[0];

        //状态转移方程：
        for(int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};