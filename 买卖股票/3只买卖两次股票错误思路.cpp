#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //思考：对比上一题多了一个只能买两次的限制，这样就不能完全拆分
        //法1：统计上涨的，选两个最大的(这个方法有问题，可能不是一直增，
        //例如[1,2,4,2,5,7,2,4,9,0])
        //法2：动态规划中加上交易次数
        int n = prices.size();
        if(n <= 1) return 0;
        int dh = 0, max1 = 0, max2 = 0;
        int i = 0;
        while(i < n - 1){
            while(i < n - 1 && prices[i + 1] - prices[i] >= 0){
                dh += prices[i + 1] - prices[i];
                i++;
            }
            if(dh > max1){
                max2 = max1;
                max1 = dh;
            }else{
                if(dh > max2){
                    max2 = dh;
                }
            }
            dh = 0;
            i++;
        }
        return max1 + max2;
    }
};