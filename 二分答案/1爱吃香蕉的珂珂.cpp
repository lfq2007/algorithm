#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(vector<int> &piles, int k) {
        int t = 0;
        int n = piles.size();
        int i = 0;
        while (i < n) {
            if (piles[i] <= k) {
                i++;
                t++;
            }
            else{
                piles[i] -= k;
                t++;
            }
        }
        //这里写for(int p: piles) {整除向上取整：(p + k - 1) / k;} &会改变值
        return t;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        //k为max(piles[i])时，最短时间为n < h，k减小time增大
        int n = piles.size();
        int l = 1, r = *std::max_element(piles.begin(), piles.end()), mid;
        while (l < r) {
            mid = (r - l) / 2 + l;
            int res = check(piles, mid);
            if (res < h) {
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;//注意返回值
    }
};
/*
分析：k越大h就越小单调，转换成给定k，就不需要讨论，直接获得时间与h比较
*/
/*
珂珂喜欢吃香蕉。这里有 n 堆香蕉，第 i 堆中有 piles[i] 根香蕉。警卫已经离开了，将在 h 小时后回来。
珂珂可以决定她吃香蕉的速度 k （单位：根/小时）。每个小时，她将会选择一堆香蕉，从中吃掉 k 根。如果这堆香蕉少于 k 根，
她将吃掉这堆的所有香蕉，然后这一小时内不会再吃更多的香蕉。  
珂珂喜欢慢慢吃，但仍然想在警卫回来前吃掉所有的香蕉。
返回她可以在 h 小时内吃掉所有香蕉的最小速度 k（k 为整数）。
示例 1：
输入：piles = [3,6,7,11], h = 8
输出：4
*/