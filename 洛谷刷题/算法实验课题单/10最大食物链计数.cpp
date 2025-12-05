#include<bits/stdc++.h>
using namespace std;
int main() {
    const int MOD = 80112002;
    int n, m;
    cin >> n >> m;
    vector<int>producer;
    vector<int>top_consumer;
    vector<int>in_degree(n,0);
    vector<int>out_degree(n,0);
    vector<vector<int>>preys(n);
    vector<int>dp(n,0);
    queue<int>q;
    int ans = 0;


    for (int i = 0; i < m; i++) {
        int prey, predator;
        cin >> prey >> predator;
        prey--;predator--;
        preys[prey].push_back(predator);
        in_degree[predator]++;
        out_degree[prey]++;
    }


    for (int i = 0; i < n; i++) {
        if (in_degree[i] == 0) {
            producer.push_back(i);
        }
        if (out_degree[i] == 0) {
            top_consumer.push_back(i);
        }
    }


    for (int i = 0; i < producer.size(); i++) {
        dp[producer[i]] = 1;
        q.push(producer[i]);
    }
    while (!q.empty()) {
        int size = q.size();
        //for (int i = 0; i < size; i++) {
            int cur = q.front();
            q.pop();
            for (int j = 0; j < preys[cur].size(); j++) {
                int cur_predator = preys[cur][j];
                in_degree[cur_predator]--;
                dp[cur_predator] = (dp[cur_predator] + dp[cur]) % MOD;
                if (in_degree[cur_predator] == 0) {
                    q.push(cur_predator);
                }
            }
        //}
    }


    for (int i = 0; i < top_consumer.size(); i++) {
        ans = (ans + dp[top_consumer[i]]) % MOD;
    }

    cout << ans;
    return 0;
}