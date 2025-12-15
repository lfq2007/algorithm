#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    int f[100002][30];
    int lg[100002];
    lg[1] = 0;
    for (int i = 2; i <= m; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> f[i][0];
    }
    for (int j = 1; j <= lg[m]; j++) {
        for (int i = 1; i <= m - (1 << j) + 1; i++) {
            f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
        }
    }

    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        int l = lg[y - x + 1];
        cout << min(f[x][l], f[y - (1 << l) + 1][l]) << ' ';
    }
    return 0;
}