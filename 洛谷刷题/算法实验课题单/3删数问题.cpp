#include<bits/stdc++.h>
using namespace std;
int main(){
    string n;
    int k;
    int i = 0;
    cin >> n >> k;
    n += '\x01';
    while(k){
        for(i = 0; i < (int)n.size() - 1 && n[i] <= n[i + 1];){
            i++;
        }
        n.erase(i,1);
        k--;
    }
    n.pop_back();
    while(n[0] == '0' && n.size() > 1){
        n.erase(0,1);
    }
    cout << n;
    return 0;
}