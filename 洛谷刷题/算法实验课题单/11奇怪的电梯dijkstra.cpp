#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, a, b, ans = 0;
    const int MAX = 0x3f3f3f3f;
    cin >> n >> a >> b;
    vector<int>k(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }    
    vector<int>dist(n + 1, MAX);
    dist[a] = 0;
    priority_queue<pair<int,int>,vector<pair<int, int>>,greater<pair<int,int>>>q;
    q.push({0,a});
    while (!q.empty()) {
        auto [step, cur] = q.top();
        q.pop();
        if (cur == b) {
            cout << step;
            return 0;
        }
        if (step > dist[cur]) continue;
        int up = cur + k[cur];
        int down = cur - k[cur];
        if (up <= n && dist[up] > dist[cur] + 1) {
            dist[up] = dist[cur] + 1;
            q.push({dist[up],up});
        }
        if (down >= 1 && dist[down] > dist[cur] + 1) {
            dist[down] = dist[cur] + 1;
            q.push({dist[down],down});
        }        
    }
    cout << -1;
    return 0;
}