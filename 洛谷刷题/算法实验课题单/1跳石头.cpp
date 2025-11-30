#include<bits/stdc++.h>
using namespace std;
int l,n,m;
vector<int> li;

int check(int mid){
    int re = 0;
    int last = 0;
    for(int i = 0; i < n; i++){
        if(li[i] - last < mid){
            re++;
        }
        else{
            last = li[i];  
        }
    }
    //终点
    if(l - last < mid) re++;
    return re <= m;
}

int main(){
    cin >> l >> n >> m;
    li.resize(n);
    for(int i = 0; i < n; i++){
        cin >> li[i];
    }
    int left = 1, r = l;
    int ans = 0;
    while(left <= r){
        int mid = left + (r - left) / 2;//防止溢出
        if(check(mid)){
            ans = mid;
            left = mid + 1;
        }else{
            r = mid - 1;
        }
    }
    cout << ans;
    /*vector<int>gap(n + 1);
    gap[0] = li[0];
    for(int i = 1; i <= n; i++){
        gap[i] = li[i] - li[i - 1];
    }*/
    //现在的想法是，找到最小区间，合并相邻两个区间（优先合并小的）
    return 0;
}
//最大化最小值，最小化最大值，二分答案