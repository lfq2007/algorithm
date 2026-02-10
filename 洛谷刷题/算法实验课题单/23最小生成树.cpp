#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
int fa[MAXN];

struct Edge{
    int u, v, w;
    //这里如果重载<，写法是
    /*bool operator<(const &Edge other) const{
        return w < other.w;
    }
    */
};

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

vector<Edge>edges;

int find(int x) {
    if (fa[x] != x) {
        fa[x] = find(fa[x]);
    }
    return fa[x];
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    fa[y] = x;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    edges.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    } 
    sort(edges.begin(), edges.end(), cmp);
    
    long long sum = 0;
    int cnt = 0;

    for(auto &e : edges) {
        if (unite(e.u, e.v)) {
            sum += e.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }

    if (cnt == n - 1)
        cout << sum << endl;
    else
        cout << "orz" << endl;  
          
    return 0;
}
//最小生成树：建立联通集合，依次选最小不联通边，kruskal
//从一个点依次选较小不联通边，prim
//kruskal,难点在并查集判环和边的数据构造
