#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAXN = 500000 + 5;
int n, m;
ll bit[MAXN];
int lowbit(int x) {
    return x & -x;
}

void add(int x, ll v) {
    while (x <= n) {
        bit[x] += v;
        x += lowbit(x);
    }
}

ll sum(int x) {
    ll res = 0;
    while (x > 0) {
        res += bit[x];
        x -= lowbit(x);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    vector<ll> a(n + 1), d(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        d[i] = a[i] - a[i - 1];
        add(i, d[i]);
    }
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int x, y;
            ll k;
            cin >> x >> y >> k;
            add(x, k);
            if (y + 1 <= n) add(y + 1, -k);
        } else {
            int x;
            cin >> x;
            cout << sum(x) << '\n';
        }
    }    
    return 0;
}