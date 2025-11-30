#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //问题：要保证总价格最高，需要考虑价格和占用
        //换个角度思考，求上涨总和
        int ans = 0;
        int dh = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if((dh = prices[i + 1] - prices[i]) > 0){
                ans += dh;
            }
        }
        return ans;
    }
};