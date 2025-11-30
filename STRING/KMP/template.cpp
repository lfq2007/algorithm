//给你两个字符串 haystack 和 needle ，
//请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。
//如果 needle 不是 haystack 的一部分，则返回  -1 。
#include<bits/stdc++.h>
using namespace std;

void get_next(string needle, int* next){
    int i = 1, j = 0;
    next[0] = 0;
    int l = needle.size();
    while(i < l){
        if(needle[i] == needle[j]){
            next[i++] = ++j;
        }
        else{
            if(j > 0){
                j = next[j - 1];
            }
            else{
                next[i++] = 0;
            }
        }
    }
}

int strStr(string haystack, string needle){
    int lh = haystack.size();
    int ln = needle.size();
    int i = 0, j = 0;
    if(ln == 0) return 0;
    int* next = new int[ln];
    get_next(needle, next);
    while(i < lh){
        if(haystack[i] == needle[j]){
            i++;
            j++;
        }
        else{
            if(j > 0){
                j = next[j - 1];
            }
            else{
                i++;
            }
        }
        if(j == ln) return i - j;
    }
    return -1;
}