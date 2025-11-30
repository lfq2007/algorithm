//给你一个字符串 s（由小写英文字母组成）和一个整数 k。

//你的任务是删除字符串中的一些字符（可以不删除任何字符），
//使得结果字符串中的 不同字符数量 最多为 k。

//返回为达到上述目标所需删除的 最小 字符数量。

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minDeletion(string s, int k) {
        //先统计所有字母cnt[i] = n数量，将cnt放入nums数组中，从最小开始删除直到K
        vector<int>cnt(26,0);
        vector<int>nums;
        int ans = 0;
        for(char ch: s){
            int c = ch - 'a';
            cnt[c]++;
        }
        for(int i = 0; i < 26; i++){
            if(cnt[i]){
                nums.push_back(cnt[i]);
            }
        }
        sort(nums.begin(),nums.end(),greater<int>());
        while(nums.size()>k){
            ans += nums.back();
            nums.pop_back();
        }
        return ans;
    }
};
//更好的方法是直接正向