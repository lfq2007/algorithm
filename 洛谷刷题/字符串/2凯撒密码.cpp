#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        putchar(((s[i] - 'a' + n) % 26) + 'a');
    }
    return 0;
}