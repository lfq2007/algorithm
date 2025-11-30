#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,y,cnt = 0;
    cin >> n >> m >> x >> y;
    vector<vector<int>>chess(n,vector<int>(m,-1));
    queue<pair<int,int>>q;
    int k[8][2] = {{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2},{1,-2},{2,-1}};
    chess[x - 1][y - 1] = 0;
    q.push({x - 1,y - 1});
    while(!q.empty()){
        cnt++;
        int size = q.size();
        for(int i = 0; i < size; i++){
            int nx = q.front().first;
            int ny = q.front().second;
            q.pop();
            for(int j = 0; j < 8; j++){
                int xt = nx + k[j][0];
                int yt = ny + k[j][1];
                if(xt >= 0 && xt < n && yt >= 0 && yt < m && chess[xt][yt] == -1){
                    chess[xt][yt] = cnt;
                    q.push({xt,yt});
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << chess[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}