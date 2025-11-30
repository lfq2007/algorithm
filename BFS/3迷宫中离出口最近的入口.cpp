//给你一个 m x n 的迷宫矩阵 maze （下标从 0 开始），
//矩阵中有空格子（用 '.' 表示）和墙（用 '+' 表示）。
//同时给你迷宫的入口 entrance ，用 entrance = [entrancerow, entrancecol] 表示
//你一开始所在格子的行和列。

//每一步操作，你可以往 上，下，左 或者 右 移动一个格子。
//你不能进入墙所在的格子，你也不能离开迷宫。你的目标是找到离 entrance 最近 的出口。
//出口 的含义是 maze 边界 上的 空格子。entrance 格子 不算 出口。

//请你返回从 entrance 到最近出口的最短路径的 步数 ，如果不存在这样的路径，请你返回 -1 。
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        int x0 = entrance[0];
        int y0 = entrance[1];
        vector<int>stepx = {1,-1,0,0};
        vector<int>stepy = {0,0,1,-1};
        queue<pair<int,int>>q;
        q.push({x0,y0});
        maze[x0][y0] = '+';
        int ans = 0;
        while(!q.empty()){
            ans++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int nx = x + stepx[k];
                    int ny = y + stepy[k];
                    if(nx < m && nx >= 0 && ny < n && ny >= 0 && maze[nx][ny] == '.'){
                        if(nx == m - 1|| nx == 0 || ny == n - 1|| ny == 0) return ans;
                        maze[nx][ny] = '+';//注意这里节点标记的时机以及角标
                        q.push({nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};
