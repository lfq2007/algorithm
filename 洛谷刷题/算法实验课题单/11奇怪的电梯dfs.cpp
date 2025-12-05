#include<bits/stdc++.h>
using namespace std;
//vector<int>memo;
vector<int>k;
vector<int>dist;
int n, a, b;
const int MAX = 0x3f3f3f3f;

int dfs(int cur){//dfs[cur]表示cur节点到b的最短路径
    if (cur == b) return 0;
    if (k[cur] == 0) return MAX;
    int up = cur + k[cur];
    int down = cur - k[cur];
    int up_ans = MAX, down_ans = MAX;
    if (up <= n && dist[up] > dist[cur] + 1) {
        dist[up] = dist[cur] + 1;
        up_ans = dfs(up);
    }
    if (down > 0 && dist[down] > dist[cur] + 1) {
        dist[down] = dist[cur] + 1;
        down_ans = dfs(down);
    }
    int best = MAX;
    if (up_ans != MAX) {
        best = min(best, up_ans + 1);
    }
    if (down_ans != MAX ) {
        best = min(best, down_ans + 1);
    }
    return best;
}

int main() {
    cin >> n >> a >> b;
    k.resize(n + 1);
    dist.resize(n + 1, MAX);
    dist[a] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    //memo.resize(n + 1,-1);
    int ans = dfs(a);
    cout << ((ans >= MAX / 2) ? -1 : ans);
    return 0;
}