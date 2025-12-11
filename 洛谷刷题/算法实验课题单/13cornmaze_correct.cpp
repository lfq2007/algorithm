#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; 
    cin >> n >> m;
    char grid[n][m];
    vector<vector<int> > dist (n, vector<int> (m, -1));//最佳写法，同时替代time和visited
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int sx, sy;
    int ex, ey;
    vector<pair<int, int> > tele[26][2];
    vector<vector<int> > teleNum(n, vector<int>(m, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            grid[i][j] = tmp;
            if (isalpha(tmp)) {
                int idx = grid[i][j] - 'A';
                if (tele[idx][0].empty()) {
                    tele[idx][0].push_back({i, j});
                    teleNum[i][j] = 0;
                } else {
                    tele[idx][1].push_back({i, j});
                    teleNum[i][j] = 1;
                }
            }
            else if (tmp == '@') {
                sx = i;
                sy = j;
            }
            else if (tmp == '=') {
                ex = i;
                ey = j;
            }
        }
    }
    //vector<pair<int, int>> tele[26];tele[n]就代表是个一维数组，n个元素，每个元素是前面的东西
    //cout << "no p" << '\n';
    queue<pair<int, int> > q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    while (!q.empty()) {
        
        auto[cx, cy] = q.front();
        q.pop();

        //cout << "time:" << ' ' << time << "cx,cy" << ' ' << cx << ' ' << cy << '\n';
        for (int k = 0; k < 4; k++) {
            int nx = cx + dx[k];
            int ny = cy + dy[k];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] != '#') {
                //cout << "time:" << ' ' << time << "nx,ny" << ' ' << nx << ' ' << ny << '\n';
                //if (dist[nx][ny] != -1) continue;主要问题就在这，本逻辑门不能标记
                if (grid[nx][ny] == '=')
                {
                    cout << dist[cx][cy] + 1;
                    return 0;
                }
                
                else if (isalpha(grid[nx][ny])) {
                    int idx = grid[nx][ny] - 'A';
                    int num = teleNum[nx][ny];

                    int targetNum = (num + 1) % 2;

                    if (!tele[idx][targetNum].empty()) {
                        
                        int tx = tele[idx][targetNum][0].first;
                        int ty = tele[idx][targetNum][0].second;

                        if (dist[tx][ty] == -1) {
                            dist[tx][ty] = dist[cx][cy] + 1;
                            q.push({tx, ty});
                        }
                    } else {
                        // 如果只有一个传送门，就当作普通点
                        if (dist[nx][ny] == -1) {
                            dist[nx][ny] = dist[cx][cy] + 1;
                            q.push({nx, ny});
                        }
                    }
                }
                else{
                    if (dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[cx][cy] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        
    }
    return 0;
}