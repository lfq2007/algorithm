//给你一个数组 power ，其中每个元素表示一个咒语的伤害值，可能会有多个咒语有相同的伤害值。
//已知魔法师使用伤害值为 power[i] 的咒语时，他们就 不能 使用伤害为 power[i] - 2 ，
//power[i] - 1 ，power[i] + 1 或者 power[i] + 2 的咒语。
#include<bits/stdc++.h>
#include<ranges>
using namespace std;
class Solution{
public:
    long long maximumTotalDamage(vector<int>&power){
        unordered_map<int,int>cnt;
        for(int x : power){
            cnt[x]++;
        }

        vector<pair<int,int>>a(cnt.begin(),cnt.end());
        sort(a.begin(),a.end());
        int n = a.size();
        vector<long long>f(n + 1);
        for(int i = 0, j = 0; i < n; i++){
            auto& [x,c] = a[i];
            while(a[j].first < x - 2){
                j++;
            }
            f[i + 1] = max(f[i],f[j] + (long long)(x * c));
        }
        return f[n];
    }
};