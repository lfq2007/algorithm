#include<bits/stdc++.h>
using namespace std;
//vector<int>memo;
vector<int>k;
vector<int>visited;
int n, a, b;
const int MAX = 0x3f3f3f3f;

int dfs(int cur){//dfs[cur]表示cur节点到b的最短路径
    if (visited[cur] == 1) return MAX;//这里的visited数组用来阻塞环，
    //退出本条路径后会还原
    if (cur == b) return 0;
    //if (memo[cur] != -1) return memo[cur];//已经走过这条路，就会被标记，
    //问题？是最短路吗，确实是
    visited[cur] = 1;
    int up = cur + k[cur];
    int down = cur - k[cur];
    int up_ans = (up <= n) ? dfs(up) : MAX;
    int down_ans = (down > 0) ? dfs(down) : MAX;
    int best = MAX;
    if (up_ans != MAX) best = min(best, up_ans + 1);
    if (down_ans != MAX) best = min(best, down_ans + 1);
    //memo[cur] =  best;
    visited[cur] = 0;
    //return memo[cur];
    return best;
}

int main() {
    cin >> n >> a >> b;
    k.resize(n + 1);
    visited.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    //memo.resize(n + 1,-1);
    int ans = dfs(a);
    cout << ((ans >= MAX / 2) ? -1 : ans);
    return 0;
}