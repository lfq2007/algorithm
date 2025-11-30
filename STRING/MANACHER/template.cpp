#include<bits/stdc++.h>
using namespace std;
int Manacher(string s){        //1.暴力
    string t = "";             //2.扩展字符可以随意设计
    for(char c : s){           //3.回文半径和真实回文长度对应，len = p[i] - 1
        t += '#';              //4.扩展回文串结尾下标和真实回文串终止位置的对应
        t += c;                //，真实位置=下标/2
    }                    //5.回文半径数组p[i],回文覆盖最右边界r，回文中心c      
    t += "#";            //6.a.没被包住，以i为中心扩展
    int n = t.size();    //b.被包住，对称点2*c - i，回文半径，在大回文区域内，
    vector<int> p(n);    //p[i] = p[2 * c - i]
    int ans = 0;      //c.外：p[i] = r - i d.撞线：从r之外扩展
    for(int i = 0, c = 0, r = 0,len; i < n; i++){
//        len = (r > i) ? min(p[2 * c- i], r - i) : 1;
        if (i <= r && 2*c - i >= 0) {
            len = min(p[2*c - i], r - i);
        } else {
            len = 1;
        }
        while(i + len < n && i - len >= 0 && t[i + len] == t[i - len]){
            len++;
        }
        if(i + len > r){
            r = i + len;
            c = i;
        }
        ans = max(ans,len);
        p[i] = len;
        //if(len > ans){
        //    ans = len
        //    best_i = i;}
        //int start = (best_i - ans + 1) / 2;
        //return s.substr(start,ans - 1);ans是半径，需-1
    }
    return ans - 1;

}