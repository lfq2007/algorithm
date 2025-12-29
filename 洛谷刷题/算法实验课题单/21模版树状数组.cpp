#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<long long>tree;

int lowbit(int x) {
    return x & -x;
}

void add(int x, long long k) {
    while (x <= n) {
        tree[x] += k;
        x = x + lowbit(x);//举个例子对10101 这几个10110 11000 100000（剩下就是左移了，）区间覆盖它，
        //要求本身比他大，去了末尾1又比他小
    }
}

long long query(int x) {
    long long res = 0;
    while (x > 0) {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

long long range_sum(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    tree.resize(n + 1);

    /*for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        add(i, x);
    }*/
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        tree[i] = a[i];
    }

    for (int i = 1; i <= n; i++) {
        int j = i + lowbit(i);
        if (j < n) {
            tree[j] += tree[i];
        }
    }

    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 1) {
            add(x, y);
        } else {
            cout << range_sum(x, y) << '\n';
        }
    }
    return 0;
}