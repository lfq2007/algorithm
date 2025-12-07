#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, m; // 节点数、边数
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n+1); // u -> [(v, w), ...]
    vector<int> dist(n+1, INT_MAX);
    vector<int> pre(n+1, -1);
    vector<int> in_queue(n+1, 0);
    vector<int> cnt(n+1, 0);


    for(int i=0; i<m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int start = 1; // 起点，根据题目输入
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    in_queue[start] = 1;
    cnt[start] = 1;

    while(!q.empty()){
        int u = q.front(); q.pop();
        in_queue[u] = 0;

        for(auto [v, w] : adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                pre[v] = u;   // 更新前驱
                if(!in_queue[v]){
                    q.push(v);
                    in_queue[v] = 1;
                    cnt[v]++;
                    if(cnt[v] > n){
                        cout << "Negative Cycle Detected\n";
                        return -1;
                    }
                }
            }
        }
    }

    vector<int> path;
    int target = n; // 终点，根据题目
    if(dist[target] == INT_MAX) {
        cout << "No path\n";
    } else {
        for(int cur = target; cur != -1; cur = pre[cur]){
            path.push_back(cur);
            if(cur == start) break;
        }
        reverse(path.begin(), path.end());
    }

    return 0;
}