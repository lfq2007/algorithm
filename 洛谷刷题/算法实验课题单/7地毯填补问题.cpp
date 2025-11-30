#include<bits/stdc++.h>
using namespace std;
void solve(int k, int x, int y, int r, int c) {
    if (k == 1) {
        if (x == r + 0 && y == c + 0) {
            cout << r + 1 + 1 << ' ' << c + 1 + 1 << ' ' << 1 << endl;
        }
        else if (x == r + 0 && y == c + 1) {
            cout << r + 1 + 1<< ' ' << c + 1<< ' ' << 2 << endl;
        }
        else if (x == r + 1 && y == c + 0) {
            cout << r + 1 << ' ' << c + 1 + 1 << ' ' << 3 << endl;
        }
        else {
            cout << r + 1 << ' ' << c + 1 << ' ' << 4 << endl;
        }
        return;
    }
    else{
        int len = 1 << k - 1;
        if (x >  r + len - 1) {
            if (y > c + len - 1) {
                solve(k - 1, x, y, r + len, c + len);
                solve(k - 1, r + len - 1, c + len, r + 0, c + len);
                solve(k - 1, r + len - 1, c + len - 1, r + 0, c + 0);
                solve(k - 1, r + len, c + len - 1, r + len, c + 0);
                cout << r + len - 1 + 1 << ' ' << c + len - 1 + 1 << ' ' << 4 << endl;
            }
            else {
                solve(k - 1, x, y, r + len, c + 0);
                solve(k - 1, r + len - 1, c + len - 1, r + 0, c + 0);
                solve(k - 1, r + len - 1, c + len, r + 0, c + len);
                solve(k - 1, r + len, c + len, r + len, c + len);
                cout << r + len - 1 + 1 << ' ' << c + len + 1 << ' ' << 3 << endl;
            }
        }
        else{
            if(y > c + len - 1){
                solve(k - 1, x, y, r + 0, c + len);
                solve(k - 1, r + len - 1, c + len - 1, r + 0, c + 0);
                solve(k - 1, r + len, c + len - 1, r + len, c);
                solve(k - 1, r + len, c + len, r + len, c + len);
                cout << r + len + 1 << ' ' << c + len - 1 + 1 << ' ' << 2 << endl;
            }
            else{
                solve(k - 1, x, y, r + 0, c + 0);
                solve(k - 1, r + len - 1, c + len, r + 0, c + len);
                solve(k - 1, r + len, c + len, r + len, c + len);
                solve(k - 1, r + len, c + len - 1,r + len, c + 0);
                cout << r + len + 1 << ' ' << c + len + 1 << ' '<< 1 << endl;
            }
        }
    }
}
int main() {
    int k, x, y;
    cin >> k >> x >> y;
    solve(k,x - 1,y - 1,0,0);
    return 0;
}