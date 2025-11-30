#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int climbStairs(int n) {
        int f0 = 1;
        int f1 = 1;
        int f;
        for(int i = 2; i <= n; i++){
            f = f1 + f0;
            f0 = f1;
            f1 = f;
        }
        return f1;// return f会导致n=0时返回未定义的f
    }
};

int main(){

    return 0;
}