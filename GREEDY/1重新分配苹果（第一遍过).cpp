//给你一个长度为 n 的数组 apple 和另一个长度为 m 的数组 capacity 。

//一共有 n 个包裹，其中第 i 个包裹中装着 apple[i] 个苹果。
//同时，还有 m 个箱子，第 i 个箱子的容量为 capacity[i] 个苹果。

//请你选择一些箱子来将这 n 个包裹中的苹果重新分装到箱子中，
//返回你需要选择的箱子的 最小 数量。

//注意，同一个包裹中的苹果可以分装到不同的箱子中。
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.begin(),capacity.end());
        int sum = 0;
        int ans = 0;
        for(int i = 0; i < n; i++){
            sum += apple[i];
        }
        int cur = m - 1;
        while(cur >= 0 && sum > 0){
            ans++;
            sum -= capacity[cur];
            cur--;
        }
        return ans;
    }
};