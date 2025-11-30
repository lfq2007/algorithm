#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(3,vector<int>(2,-100000)));

        
        dp[0][0][0] = 0;
        dp[0][0][1] = -1 * prices[0];
        

        for(int i = 1; i < n; i++){
            dp[i][0][0] = 0;
            dp[i][0][1] = max(dp[i - 1][0][1],-1 * prices[i]);
            for(int k = 1; k < 3; k++){
                dp[i][k][0] = max(dp[i - 1][k][0],dp[i - 1][k - 1][1] + prices[i]);
                dp[i][k][1] = max(dp[i - 1][k][1],dp[i - 1][k][0] - prices[i]);
            }
        }
        return max(dp[n-1][2][0],max(dp[n -1][1][0],0));
    }
};