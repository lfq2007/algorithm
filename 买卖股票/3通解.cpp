#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int k = 2; // 交易k次
        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);//逻辑上不成立的用INT_MIN
        for (int price : prices) {
            for (int i = 1; i <= k; ++i) {
                buy[i] = max(buy[i], sell[i - 1] - price);
                sell[i] = max(sell[i], buy[i] + price);
            }
        }
        return sell[k];
    }
};
//这里其实相当于对交易天数进行了空间优化