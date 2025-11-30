#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {

        //规律：p + q = s, p - q = t ,p = ( s + t )/ 2,q = (s - t) / 2;
        int n = nums.size();
        int s = accumulate(nums.begin(),nums.end(),0);
        if((s + target) % 2 != 0) return 0;
        int p = (s + target) / 2;        
        if(p < 0) return 0;
        //在s里面挑出来p的和
        //f[i + 1][j] = f[i][j];f[i + 1][j] = f[i][j - nums[i]] || f[i][j];
        vector<vector<int>>f(n + 1,vector<int>(p + 1));
        f[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p + 1; j++){
                f[i + 1][j] += f[i][j];
                if(j >= nums[i]){
                    f[i + 1][j] += f[i][j - nums[i]];
                }
            }
        }
        return f[n][p];
    }
};
//这题的关键是找到加减的数量关系转为01背包问题