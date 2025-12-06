#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, a, b, ans = 0;
    const int MAX = 0x3f3f3f3f;
    cin >> n >> a >> b;
    vector<int>k(n + 1, 0);
    vector<int>visited(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    
    queue<int>q;
    q.push(a);
    visited[a] = 1;
    int flg = 0;
    while (flg == 0 && !q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int cur = q.front();
            if (cur == b) {
                flg = 1;
                cout << ans;
                return 0;
            }
            q.pop();
            int up = cur + k[cur];
            int down = cur - k[cur];
            if (up <= n && !visited[up]) {
                visited[up] = 1;
                q.push(up);
                
            }
            if (down >= 1 && !visited[down]) {
                visited[down] = 1;
                q.push(down);
                
            }
        }
        ans++;
    }
    cout << -1;
    return 0;
}