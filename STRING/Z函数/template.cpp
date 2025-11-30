#include<bits/stdc++.h>
using namespace std;
vector<int>z,e;
void zArray(char s[], int n){//从i开始，与本字符串的匹配长度
    z.resize(n);
    z[0] = n;
    for(int i = 1, c = 1, r = 1, len; i < n; i++){
        len = r > i ? min(r - i,z[i - c]) : 0;
        while(i + len < n && s[i + len] == s[len]){
            len++;
        }
        if(i + len > r){
            r = i + len;
            c = i;
        }
        z[i] = len;
    }
}

void eArray(char a[],char b[], int n, int m){
    e.resize(n);
    for(int i = 0, c = 0, r = 0, len; i < n; i++){
        len = r > i ? min(r - i,z[i - c]) : 0;
        while(i + len < n && len < m && a[i + len] == b[len]){
            len++;
        }
        if(i + len > r){
            r = i + len;
            c = i;
        }
        e[i] = len;
    }
}