#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> cache;
    int dfs(int i){
        if(i <= 1) return 1;
        if(cache[i] != -1) return cache[i];
        return cache[i] = dfs(i - 1) + dfs(i - 2);
    }
public:
    int climbStairs(int n) {
        cache.resize(n + 1, -1);
        cache[0] = 1;
        cache[1] = 1;
        return dfs(n);
    }
};

int main(){

    return 0;
}
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？