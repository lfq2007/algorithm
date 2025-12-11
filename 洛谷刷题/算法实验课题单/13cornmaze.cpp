#include<bits/stdc++.h>
using namespace std;
int main() {
    const int N = 300;
    const int M = 300;
    int n, m; 
    cin >> n >> m;
    char grid[n][m];
    vector<vector<int> > dist (n, vector<int> (m, -1));//最佳写法，同时替代time和visited
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int sx, sy;
    int ex, ey;
    vector<pair<int, int> >  teleA(26, {N + 1, N + 1});
    vector<pair<int, int> >  teleB(26, {N + 1, N + 1});//这里最好写成两个，像这样，不要再嵌套数组了
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char tmp;
            cin >> tmp;
            grid[i][j] = tmp;
            if (isalpha(tmp)) {
                if (teleA[tmp - 'A'].first != N + 1) {
                    teleB[tmp - 'A'] = {i, j};
                }
                else{
                    teleA[tmp - 'A'] = {i, j};
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
                if (dist[nx][ny] != -1) continue;
                else if (grid[nx][ny] == '=')
                {
                    cout << dist[cx][cy] + 1;
                    return 0;
                }
                else if (isalpha(grid[nx][ny])) {
                    int num = grid[nx][ny] - 'A';
                    /*dist[teleA[num].first][teleA[num].second] = dist[cx][cy] + 1;
                    dist[teleB[num].first][teleB[num].second] = dist[cx][cy] + 1;
                     因为可能有其他最短路到另一端，所以不能赋值，仍需要判断*/



                    //很坑的点在于传送门不止可以用一次，有时候需要传走再随便走一步传回来
                    if (nx == teleA[num].first && ny == teleA[num].second) {
                        if (dist[teleB[num].first][teleB[num].second] == -1) {
                            dist[teleB[num].first][teleB[num].second] = dist[cx][cy] + 1; 
                            q.push({teleB[num].first,teleB[num].second});
                        }
                        
                    }
                    else{
                        if (dist[teleA[num].first][teleA[num].second] == -1) {
                            dist[teleA[num].first][teleA[num].second] = dist[cx][cy] + 1; 
                            q.push({teleA[num].first,teleA[num].second});
                        }
                                                
                    }
                }
                else{
                    dist[nx][ny] = dist[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
        
    }
    return 0;
}