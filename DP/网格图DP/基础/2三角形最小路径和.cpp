#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>f(n,vector<int>(n,INT_MAX / 2));
        f[n - 1] = triangle[n - 1];//学习这句
        for(int i = n - 2; i >= 0; i--){
            for(int j = 0; j <= i; j++){
                f[i][j] = min(f[i + 1][j],f[i + 1][j + 1]) + triangle[i][j];
            }
        }
        return f[0][0];

    }
};
//倒序求解，这样返回最顶的