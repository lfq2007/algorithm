#include<bits/stdc++.h>
using namespace std;
int bidirection_bfs(int start, int target, vector<vector<int>> &adj){
    if (start == target) return 0;
    int n = adj.size();
    queue<int> qa, qb;
    vector<int> da(n, -1);
    vector<int> db(n, -1);
    da[start] = 0;
    db[target] = 0;
    qa.push(start);
    qb.push(target);
    while (!qa.empty() && !qb.empty()) {
        if (qa.size() <= qb.size()) {
            //扩展左边
            int size = qa.size();
            while (size--) {
                int cur = qa.front();
                qa.pop();
                for (int next : adj[cur]) {
                    if (da[next] == -1) {
                        da[next] = da[cur] + 1;
                        qa.push(next);
                        if (db[next] != -1) {
                            return db[next] + da[next];
                        }
                    }
                }
            }

        }
        else{
            //扩展右边
            int size = qb.size();

            while (size--) {
                int cur = qb.front();
                qb.pop();
                for (int next : adj[cur]) {
                    if (db[next] == -1) {
                        db[next] = db[cur] + 1;
                        qb.push(next);
                        if (da[next] != -1) {
                            return db[next] + da[next];
                        }
                    }
                }
            }
        }
    }
    return -1;
}