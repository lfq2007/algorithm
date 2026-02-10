#include<bits/stdc++.h>
using namespace std;
long long quick_pow (long long a, long long b, long long p) {
    long long res = 1;
    a %= p;
    while (b > 0) {
        if(b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long a, b, p;
    cin >> a >> b >> p;
    long long s = quick_pow(a, b, p);
    cout << a << "^" << b << " mod " << p << "=" << s << endl;
    return 0;
}
//计算a的b次方mod p，步骤是：
//将b二进制分解，对应a进行平方
/*{
    long long res = 1;
    a %= p;//这里先取余一下
    while(b) {
        if (b & 1) {
            res = (res * a) % p;
        }
        a = (a * a) % p;
        b >>= 1;
    }
}
*/