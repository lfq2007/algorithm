#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countTexts(string pressedKeys) {
        //首先做截断，统计数字和个数
        //然后动态规划得到每一步结果再相乘
        const int MOD = 1e9 + 7;
        int n = pressedKeys.size();
        if(n == 0) return 0;//长为0的判断
        int i = 0;
        char c;
        long long ans = 1;
        //注：本题只需要看方法数不需要具体字符
        while(i < n){
            c = pressedKeys[i];
            int num = 1;//注意这里的更新
            i++;
            while(i < n && pressedKeys[i] == c){
                num++;
                i++;
            }//这里是一个小段结束
            
            vector<long long>f(num + 1);
            f[0] = 1;
            for(int i = 1; i <= num; i++){
                if(c == '7' || c == '9'){//这里其实可以用一个变量简写或者不循环
                    for(int j = 1; j <= 4; j++){
                        if(i - j >= 0){
                            f[i] += f[i - j];
                            f[i] %= MOD;
                        }
                    }
                }
                else{
                    for(int j = 1; j <= 3; j++){
                        if(i - j >= 0){
                            f[i] += f[i - j];
                            f[i] %= MOD;
                        }
                    }
                }
            }
            ans = (ans * f[num]) % MOD;
        }
        return (int)ans;
    }
};