#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //不需要一次找到最小值，按顺序维护就不会漏掉
        int minnum = INT_MAX;
        int ans = 0;
        for(int x: prices){
            minnum = min(minnum,x);
            ans = max(ans,x - minnum);
        }
        return ans;
    }
};