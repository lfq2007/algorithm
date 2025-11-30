#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int>f(n + 1,INT_MAX);
        int d[3] = {1,7,30};
        f[n] = 0;
        for(int i = n - 1; i >= 0; i--){
            for(int k = 0; k < 3; k++){
                int j = i;
                while(j < n && days[j] <= days[i] + d[k] - 1){
                    j++;
                }
                f[i] = min(f[i],costs[k] + f[j]);
            }
        }
        return f[0];
    }
};
//这里的思路是从后往前，买了k天的就转化为K天后的，所以初始条件在后面
//还有一种思路是从前往后，看看上一个最多持续到哪（或者说思路一样，其实就是减法版,
//但是影响了初始化和边界判断，可以根据这些确定从前往后还是从后往前）