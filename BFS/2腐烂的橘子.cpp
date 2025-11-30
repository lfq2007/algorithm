#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //先遍历一遍，记录好的橘子数，坏的入队
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>k = {{1,0},{-1,0},{0,1},{0,-1}};

        queue<pair<int,int>>q;
        int fresh = 0;
        int time = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i,j});
            }
        }
        //无新腐烂检查剩余橘子数，剩余返回-1，不剩返回时间
        while(!q.empty()){
            int flg = 0;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j = 0; j < 4; j++){
                    int nx = x + k[j][0];
                    int ny = y + k[j][1];
                    if(nx < m && nx >= 0 && ny < n && ny >= 0 && grid[nx][ny] == 1){
                        grid[nx][ny] = 2;
                        q.push({nx,ny});
                        fresh--;
                        flg = 1;
                    }
                }
            }
            if(flg == 1) time++;//或者直接把条件改成fresh&& !q.empty()
        }
        if(fresh > 0) return -1;
        return time;
    }
};

//在给定的 m x n 网格 grid 中，每个单元格可以有以下三个值之一：

//值 0 代表空单元格；
//值 1 代表新鲜橘子；
//值 2 代表腐烂的橘子。
//每分钟，腐烂的橘子 周围 4 个方向上相邻 的新鲜橘子都会腐烂。

//返回 直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1 。