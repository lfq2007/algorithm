#include<bits/stdc++.h>
using namespace std;

int isPrime(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

int main(){
    string s;
    cin >> s;
    vector<int>cnt(26);
    for(int i = 0; i < s.size(); i++){
        cnt[s[i] - 'a']++;
    }
    //sort(cnt.begin(),cnt.end());
    //int maxn = cnt.back();
    //int minn = cnt.front();这样做会使最小是0，因为有的字母没出现
    int maxn = INT_MIN / 2;
    int minn = INT_MAX / 2;
    for(int x: cnt){
        if(x > 0){
            maxn = max(maxn,x);
            minn = min(minn,x);
        }
    }
    int ans = maxn - minn;
    if(isPrime(ans)){
        cout << "Lucky Word\n";
        cout << ans;
    }
    else{
        cout << "No Answer\n";
        cout << 0;
    }
    return 0;
}