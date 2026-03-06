#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &power, int beg) {
    int n = power.size();
    for (int i = 0; i < n; i++) {
        if (power[i] <= beg) {
            beg += beg - power[i];
        }
        else{
            beg -= power[i] - beg;
        }
        //这里可以直接统一
        if (beg < 0) return false;
        //另外，这里要加上超过最大值直接返回的剪枝优化
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int>power(n, 0);
    for (int i = 0; i < n; i++) { 
        cin >> power[i];
    }
    int l = 1, r = *max_element(power.begin(), power.end());
    while (l < r) {
        int mid = (r - l) / 2 + l;
        if (check(power, mid)) {
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }
    return l;
}