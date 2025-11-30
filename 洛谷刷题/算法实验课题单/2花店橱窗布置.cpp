#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>value;
vector<vector<int>>dp;
void print(int i,int j){
    if(i <= 0) return;
    for(int k = i; k <= j; k++){
        if(dp[i][j] == dp[i - 1][k - 1] + value[i][k]){
            print(i - 1,k - 1);
            cout << k << ' ';
            break;
        }
    }
}

int main(){
    int f,v;
    cin >> f >> v;
    value.resize(f + 1,vector<int>(v + 1,0));
    dp.resize(f + 1,vector<int>(v + 1,0));
    for(int i = 1; i <= f; i++){
        for(int j = 1; j <= v; j++){
            cin >> value[i][j];
        }
    }
    //dp[i][j] = max(dp[i][j],dp[i - 1][j以下各种,但>=i] + value[i][j]);
    //dp[i][j] 表示第i束花放入前j个瓶子中
    //问题在于怎么记录这个最优解 -->通过从后面找最大值比较，改变的就是最优解

    for(int i = 1; i < f; i++){
        dp[i][i] = dp[i - 1][i - 1] + value[i][i];
    }//对角线上的解是固定的，可以直接初始化，注意这里的初始化保留，需要将极小值在下面赋值

    for(int i = 1; i <= f; i++){
        for(int j = i; j <= v; j++){
            dp[i][j] = -1 * 0x3f3f3f3f;
            for(int k = i; k <= j; k++){
                dp[i][j] = max(dp[i][j],dp[i - 1][k - 1] + value[i][k]);
            }
        }
    }

    cout << dp[f][v] << endl;
    print(f,v);
    return 0;
}