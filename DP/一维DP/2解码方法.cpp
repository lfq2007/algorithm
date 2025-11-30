#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>f(n + 1,-1);
        f[n] = 1;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '0') f[i] = 0; 
            else{
                f[i] = f[i + 1];
                if(i + 1 < n && ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)){
                    f[i] += f[i + 2];
                }         
            }
        }
        return f[0];
    }
};
//重点是if(i + 1 < n && ((s[i] - '0') * 10 + s[i + 1] - '0' <= 26)){
                    //f[i] += f[i + 2]

//以及转换时if(s[i] == '0') f[i] = 0;