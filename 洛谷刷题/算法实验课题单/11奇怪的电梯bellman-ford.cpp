#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int u, v, w;
};
vector<Edge>edges;
vector<int>dist;
vector<int>pre;
int bellman_ford(int start, int target) {
    int n, m;
    cin >> n >> m; 
    const int MAX = 0x3f3f3f3f;
    dist.assign(n + 1, MAX);
    pre.assign(n + 1, -1);
    dist[start] = 0;
    edges.resize(m);
    //剪枝优化
    bool updated = false;
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    for (int i = 1; i <= n - 1; i++) {
        //注意这里是n - 1不是边m - 1
        updated = false;
        for (auto &e: edges) {
            if (dist[e.u] != MAX) {
                if (dist[e.v] > dist[e.u] + e.w) {
                    dist[e.v] = dist[e.u] + e.w;
                    updated = true;
                    pre[e.v] = e.u;
                }
            }
            //注意松弛方向以及可达的判断
            
        }
        if (!updated) break;
    }


    // 检测负环
    for (auto &e : edges) {
        if (dist[e.u] != MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative Cycle Detected\n";
            return -1;
        }
    }

    

    return dist[target];
}

vector<int> restore_path(int start, int target, vector<int> &pre, vector<int> &dist) {
    const int MAX = 0x3f3f3f3f;
    vector<int> path;

    if (dist[target] == MAX) return path;  // 无路径，返回空

    int cur = target;
    while (cur != -1) {
        path.push_back(cur);
        if (cur == start) break;   // 到达起点
        cur = pre[cur];
    }

    reverse(path.begin(), path.end());
    return path;
}
