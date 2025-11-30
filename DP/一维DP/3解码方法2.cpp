#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long dfs(string s,int i,vector<int>& f){
        int n = s.size();
        if(i >= n) return 1;//!!!尤其注意

        if(f[i] != -1) return f[i];
        long long ans = 0;
        //第一个为0直接舍去
        if(s[i] - '0' == 0) return 0;
        else{
        //第二大情况：只转换一个
        //第三大情况：转换两个

            //2.1：第一个是数
            if(isdigit(s[i])){
                ans = dfs(s,i + 1,f) % MOD;//这里的ifelse结构可以用？:
                //3.1：两个都是数字，满足和小于27
                if(i + 1 < n && isdigit(s[i + 1]) && (s[i] - '0') * 10 + s[i + 1] - '0' <=26){
                    ans = (ans + dfs(s,i + 2,f)) % MOD;
                }
                //3.2：第一个是数，第二个是星，需讨论2*并且*只代表9个
                else if(i + 1 < n && s[i + 1] == '*'){
                    if(s[i] == '1'){
                        ans = (ans + 9 * dfs(s,i + 2,f)) % MOD;
                    }else if(s[i] == '2'){
                        ans = (ans + 6 * dfs(s,i + 2,f)) % MOD;
                    }
                }
            }
            //2.2：第一个是星
            else{
                ans = (9 * (dfs(s,i + 1,f) % MOD)) % MOD;
                //3.3：第一个是*，第二个是数，需讨论第二个数与6
                if(i + 1 < n && s[i + 1] <= '6' && s[i + 1] >= '0'){
                    ans = (ans + 2 * dfs(s,i + 2,f)) % MOD;
                }
                else if(i + 1 < n && s[i + 1] > '6' && s[i + 1] <= '9'){
                    ans = (ans + dfs(s,i + 2,f)) % MOD;
                }
                //3.4：都是*，只有一定数量
                else if(i + 1 < n && s[i + 1] == '*'){
                    ans = (ans + 15 * dfs(s,i + 2,f)) % MOD;
                }
            }
        
        }
        f[i] = ans % MOD;       
        return ans % MOD;
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int>f(n,-1);
        return dfs(s,0,f);
    }
};