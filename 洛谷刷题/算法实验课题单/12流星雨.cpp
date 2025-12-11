#include<bits/stdc++.h>
using namespace std;
int main() {
    //首先，可以在流星撞击的地方用数组标记，同时记录走的时间
    //不能走的情况有：1.越界 2.步数≥格子的标记数
    //最终安全的地方：被标记为max的地方
    //如果不可能达到需要返回-1
    const int MAX = 0x3f3f3f3f;
    int k[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<int> > farm(302, vector<int> (302, MAX));
    
    int m; 
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y, t;
        cin >> x >> y >>t;
        farm[x][y] = min(farm[x][y], t);
        for (int j = 0; j < 4; j++) {
            int nex = x + k[j][0];
            int ney = y + k[j][1];
            if (nex >= 0 && ney >= 0 && nex < 302 && ney < 302) {
                farm[nex][ney] = min(farm[nex][ney], t);
            }
        }
    }

    queue<pair<int,int> > q;
    q.push({0, 0});
    farm[0][0] = 0;
    int time = 0;

    if (farm[0][0] == 0) {
        cout << -1;
        return 0;
    }

    if (farm[0][0] == MAX) {
        cout << 0;
        return 0;
    }

    while (!q.empty()) {
        time++;
        int size = q.size();

        for (int i = 0; i < size; i++) {
            auto[cur_x, cur_y] = q.front();
            q.pop();
            //cout << "time =" << time << "cur_x, cur_y:" << cur_x << ' '<< cur_y;

            for (int j = 0; j < 4; j++) {
                int next_x = cur_x + k[j][0];
                int next_y = cur_y + k[j][1];

                if (next_x >= 0 && next_y >= 0 && next_x < 302 && next_y < 302 && farm[next_x][next_y] > time) {

                    if (farm[next_x][next_y] == MAX) {
                        cout << time;
                        return 0;
                    }

                    //cout << "time =" << time << "next_x, next_y:" << next_x << ' '<< next_y;
                    farm[next_x][next_y] = 0;
                    q.push({next_x, next_y});
                }
            }
        }

        
    }
    cout << -1;
    return 0;
}