#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& arr,int repeat){
        int n = arr.size();
        int ans = 0;
        int f = 0;
        for(int i = 0; i < n * repeat; i++){
            f = max(f,0) + arr[i % n];
            ans = max(ans,f);
        }
        return ans;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        const int MOD = 1e9 + 7;
        if(k == 1) return maxSubArray(arr,1);
        long long ans = maxSubArray(arr,2);
        int s = accumulate(arr.begin(),arr.end(),0);
        ans += 1ll * max(s,0) * (k - 2);
        return ans % MOD;
    }
};
//空间撑爆了，不能直接求解，观察发现重复部分有s，分s正负讨论，
//其中最大子数组和一定在两个中间的两种证明方法值得学习