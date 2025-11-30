#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;
    int numDecodings(string s) {
        int n = s.size();
        vector<long long> f(n + 1, -1);
        f[n] = 1;

        for (int i = n - 1; i >= 0; i--) {
            long long ans = 0;
            // 第一个为0直接舍去
            if (s[i] - '0' == 0) {
                f[i] = 0;
            } else {
                // 第二大情况：只转换一个
                // 第三大情况：转换两个

                // 2.1：第一个是数
                if (isdigit(s[i])) {
                    f[i] = f[i + 1] % MOD;
                    // 3.1：两个都是数字，满足和小于27
                    if (i + 1 < n && isdigit(s[i + 1]) && (s[i] - '0') * 10 + s[i + 1] - '0' <= 26) {
                        f[i] = (f[i] + f[i + 2]) % MOD;
                    }
                    // 3.2：第一个是数，第二个是星，需讨论2*并且*只代表9个
                    else if (i + 1 < n && s[i + 1] == '*') {
                        if (s[i] == '1') {
                            f[i] = (f[i] + 9 * f[i + 2]) % MOD;
                        } else if (s[i] == '2') {
                            f[i] = (f[i] + 6 * f[i + 2]) % MOD;
                        }
                    }
                }
                // 2.2：第一个是星
                else {
                    f[i] = (9 * (f[i + 1] % MOD)) % MOD;
                    // 3.3：第一个是*，第二个是数，需讨论第二个数与6
                    if (i + 1 < n && s[i + 1] <= '6' && s[i + 1] >= '0') {
                        f[i] = (f[i] + 2 * f[i + 2]) % MOD;
                    } else if (i + 1 < n && s[i + 1] > '6' && s[i + 1] <= '9') {
                        f[i] = (f[i] + f[i + 2]) % MOD;
                    }
                    // 3.4：都是*，只有一定数量
                    else if (i + 1 < n && s[i + 1] == '*') {
                        f[i] = (f[i] + 15 * f[i + 2]) % MOD;
                    }
                }
            }
            f[i] = f[i] % MOD;
        }
        return f[0] % MOD;
    }
};