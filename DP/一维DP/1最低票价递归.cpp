#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f[366] = {0};
    int dfs(vector<int>& days, vector<int>& costs,int i){
        if(i == days.size()) return 0;
        if(f[i]) return f[i];
        int d[3] = {1,7,30};
        int ans = INT_MAX;
        for(int k = 0; k < 3; k++){
            int j = i;
            while(j < days.size() && days[j] <= days[i] + d[k] -1){
                j++;
            }
            ans = min(ans,costs[k] + dfs(days,costs,j));
        }
        f[i] = ans;
        return ans;
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return dfs(days,costs,0);
        //dfs(i,cost) ,下一个是i + cost[j]的最小top
    }
};