#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, h;
    cin >> n >> h;
    vector<tuple<int, int, int>>req;
    int visited[n + 1] = {0};//注意这里对应下标
    for (int i = 0; i < h; i++) {
        int b, e, t;
        cin >> b >> e >> t;
        req.push_back({b,e,t});
    }
    sort(req.begin(), req.end(), [&](tuple<int, int, int>a, tuple<int, int, int>b) {
        return tie(get<1>(a), get<0>(a), get<2>(a)) < tie(get<1>(b), get<0>(b), get<2>(b));
    });

    int ans = 0;
    for (int i = 0; i < h; i++) {
        int need = get<2>(req[i]);
        int pos = get<1>(req[i]);
        while (need > 0) {
            if (visited[pos] == 0) {
                visited[pos] = 1;
                for (int j = 0; j < h; j++) {
                    if (pos <= get<1>(req[j]) && pos >= get<0>(req[j])) {
                        get<2>(req[j])--;
                    }
                }
                need--;
                ans++;
            }
            pos--;
        }
    }

    cout << ans;
    return 0;
}
//思路1，贪心：先按照右端点排序，
//记录区间已经种的树
//没种的从右往左补