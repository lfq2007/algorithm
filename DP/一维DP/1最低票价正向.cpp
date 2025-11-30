#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>dp(n + 1,INT_MAX / 2);
        dp[0] = min({costs[0],costs[1],costs[2]});
        int d[3] = {1,7,30};
        for(int i = 1; i < n; i++){
            for(int k = 0; k < 3; k++){
                int j = i;
                while(j >= 0 && days[j] + d[k] > days[i]){
                    j--;
                }
                if(j < 0){
                    dp[i] = min(dp[i],costs[k]);
                }
                else{
                    dp[i] = min(dp[i],dp[j] + costs[k]);
                }
            }
        }
        return dp[n - 1];
    }
};