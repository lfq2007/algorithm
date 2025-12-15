#include<bits/stdc++.h>
using namespace std;

struct Road
{
    int x, y, t;

}a[100000];

int f[10000];

int cmp(const Road &a, const Road &b){
    return a.t < b.t;
}

int find(int x){
    return f[x] == x ? x : (f[x] = find(f[x]));
}

int main() {
    int n, m;
    int cnt = 0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a[i].x >> a[i].y >> a[i].t;
    }
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int fx = find(a[i].x);
        int fy = find(a[i].y);
        if (fx != fy) {
            f[fx] = fy;
            cnt++; 
        }
        if (cnt == n - 1) {
            cout << a[i].t;
            return 0;
        }
    }
    cout << -1;
    return 0;
}