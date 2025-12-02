#include<bits/stdc++.h>
using namespace std;
int main() {
    int r, c, ans = 1;
    cin >> r >> c;
    vector<vector<int>>grid(r,vector<int>(c));
    vector<vector<int>>dp(r,vector<int>(c,1));
    int k[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    /*
    vector<int>all;
    for (auto row : grid) {
        for (int x : row) {
            all.push_back(x);
        }
    }
    sort(all.begin(),all.end());*/
    /*priority_queue<int,vector<int>,greater<int>>q(grid.begin(),grid.end());
    while (!q.empty()){
        
    }*/

    //首先把位置存入数组并按值的大小排序
    vector<pair<int,int>>pos;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
            pos.push_back({i,j});
        }
    }
    sort(pos.begin(),pos.end(),[&](const auto &a ,const auto & b){
return grid[a.first][a.second] < grid[b.first][b.second];
    });

    //然后开始按由低到高的顺序遍历
    for (int i = 0; i < pos.size(); i++) {
        int nx = pos[i].first;
        int ny = pos[i].second;
        for (int j = 0; j < 4; j++) {
            int cx = nx + k[j][0];
            int cy = ny + k[j][1];
            int valid = 0;
            if (cx >= 0 && cx < r && cy >= 0 && cy < c) {
                valid = 1;
            }
            //注意这种问题的边界
            if (valid && grid[cx][cy] > grid[nx][ny]) {
                dp[cx][cy] = max(dp[cx][cy], dp[nx][ny] + 1);
                ans = max(ans,dp[cx][cy]);
            }
        }
    }
    cout << ans;
    return 0;
}
//注意本题还有别的解法，先不管了