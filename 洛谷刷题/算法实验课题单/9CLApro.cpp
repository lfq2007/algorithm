#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>> adj(n + 1);
    vector<int> depth(n + 1);
    //这里是1-indexed
    //建树
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int lg = 0;
    while((1 << lg) <= n) lg++;
    vector<vector<int>> parent(n + 1, vector<int> (lg + 1, 0));


    //遍历获得parent 和 depth
/*    function<void(int,int)> dfs = [&](int u, int p){
        parent[u][0] = p;
        for(int k = 1; k <= lg; k++){
            if(parent[u][k - 1] != 0){
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
            }
        }
        for(int v: adj[u]){
            if(v != p){
                depth[v] = depth[u] + 1;
                dfs(v, u);
            }
        }
    };
    dfs(s, 0);*/
    stack<pair<int,int>>stk;
    stk.push({s,0});
    depth[s] = 0;
    while (!stk.empty()){
        auto [u, p] = stk.top();
        stk.pop();

        parent[u][0] = p;
        if (u != s) depth[u] = depth[p] + 1;
        
        for(int k = 1; k <= lg; k++){
            if(parent[u][k - 1] != 0){
                parent[u][k] = parent[parent[u][k - 1]][k - 1];
            }
        }
        for(int v: adj[u]){
            if(v != p){
                stk.push({v,u});
            }
        }
    }

    function<void(int,int)> lca = [&](int x, int y){
        
        //注意此处比较深度，不要老是比较错比较坐标
        if (depth[x] < depth[y]) swap(x,y);//这里跟有个什么树还是图的题好像，以后想到了再回来补充
        int diff = depth[x] - depth[y];
            /*while(cy){

            }注意这样对比低位再删掉只能从低位开始，应该用下面的*/
        for(int k = lg; k >= 0; k--){
            if(diff & (1 << k)){
                x = parent[x][k];
            }
        }
        if (x == y) {
            cout << x << '\n';
            return;
        }
        

        //同时往上跳，这里依然不是一点点跳，而是从大往小，一步步跳到公共祖先的下面，原理是二进制分解
        for (int k = lg; k >= 0; k--){
            if (parent[x][k] != parent[y][k]) {
                x = parent[x][k];
                y = parent[y][k];
            }
        }
        cout << parent[x][0] << '\n';
        return;
    };
    while (m--) {
        int x, y;
        cin >> x >> y;
        lca(x,y);
    }
    return 0;
}