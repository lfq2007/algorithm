#include<bits/stdc++.h>
using namespace std;
int main() {
    
    return 0;
}
/*
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>stk;
        stk.push(0);//注意，stk里面存放的是坐标
        int n = height.size();
        if (n == 1) return 0;
        int ans = 0;
        for (int i = 1; i < n; i++) {
            while (!stk.empty() && height[i] >= height[stk.top()]) {
                int bottom = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int left = stk.top();
                    ans += (min(height[left],height[i]) - height[bottom]) * (i - left - 1);
                }
            }
            stk.push(i);
        }
        return ans;
    }
};
*/