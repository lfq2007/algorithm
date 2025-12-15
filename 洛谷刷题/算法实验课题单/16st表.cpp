#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int f[100002][30];
    int lg[100002];
    lg[1] = 0;
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i >> 1] + 1;
    }

    for (int i = 1; i <= n; i++) {
        cin >> f[i][0];
    }

    for (int j = 1; j <= lg[n]; j++) {
        for (int i = 1; i <= n - (1 << j) + 1; i++) {
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        int l = lg[y - x  + 1];
        cout << max(f[x][l], f[y - (1 << l) + 1][l]) << '\n';
    }

    return 0;
}
/*
初始化部分
cin >> n >> m;
lg[1] = 0;
for (int i = 2; i <= n; i++) {
    lg[i] = lg[i >> 1] + 1;
}

for (int i = 1; i <= n; i++) {
    cin >> f[i][0];
}

for (int j = 1; j <= lg[n]; j++) {
    for (int i = 1; i <= n - (1 << j) + 1; i++) {
        f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
}
*/

/*
求值部分
for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    int l = lg[y - x + 1];
    cout << max(f[x][l], f[y - (1 << l) + 1][l]) << endl;
}
*/