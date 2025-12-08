#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<vector<int>> dist;
vector<vector<int>> path;

void getPath(int i, int j, vector<int> &res) {
    if (path[i][j] == -1) {
        res.push_back(j);
        return;
    }
    int k = path[i][j];
    getPath(i, k, res);
    getPath(k, j, res);
}

int main() {
    int n, m;
    cin >> n >> m;

    dist.assign(n+1, vector<int>(n+1, INF));
    path.assign(n+1, vector<int>(n+1, -1));

    for (int i = 1; i <= n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {

                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k; // 记录第一次拆分点
                }
            }
        }
    }

    // 判断负环
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) {
            cout << "Negative Cycle Detected\n";
            return 0;
        }
    }

    // 示例输出：1 到 n 的路径
    int s = 1, t = n;
    if (dist[s][t] >= INF) {
        cout << "NO PATH\n";
    } else {
        cout << "distance = " << dist[s][t] <<"\n";
        vector<int> res;
        res.push_back(s); // 起点手动加
        getPath(s, t, res);

        for (int x : res) cout << x << " ";
        cout << "\n";
    }

    return 0;
}
