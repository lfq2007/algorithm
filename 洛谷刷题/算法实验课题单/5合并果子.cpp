#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a;
    int ans = 0;
    priority_queue<int,vector<int>,greater<int>>q;
    for(int i = 0; i < n; i++){
        cin >> a;
        q.push(a);
    }
    while(q.size() > 1){
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans = ans + x + y;
        q.push(x + y);
    }
    cout << ans;
    return 0;
}