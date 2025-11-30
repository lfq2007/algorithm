#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>f(m + 1,vector<int>(n + 1,INT_MAX / 2));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i ==  0 && j == 0) {
                    f[1][1] = grid[0][0];//这个要单独判断，也可以用f[0][1] = 0更简单
                }else{
                f[i + 1][j + 1] = min(f[i][j + 1] + grid[i][j],f[i + 1][j] + grid[i][j]);
                }//边界用max对应INT_MIN等来处理
            }
        }
        return f[m][n];
        //f[i + 1][j + 1] = min(f[i][j + 1] + grid[i + 1][j + 1],f[i + 1][j] + grid[i + 1][j + 1]);
    }
};