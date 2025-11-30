/*
输入格式
共 2 行。

第 1 行为一个字符串，其中只含字母，表示给定单词；

第 2 行为一个字符串，其中只可能包含字母和空格，表示给定的文章。

输出格式
一行，如果在文章中找到给定单词则输出两个整数，两个整数之间用一个空格隔开，分别是单词在文章中出现的次数和第一次出现的位置（即在文章中第一次出现时，单词首字母在文章中的位置，位置从 0 开始）；如果单词在文章中没有出现，则直接输出一个整数 −1。

注意：空格占一个字母位
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int cnt = 0;
    string tar;
    cin >> tar;
    getchar();
    tar = ' ' + tar + ' ';
    string s;
    getline(cin,s);
    s = ' ' + s + ' ';
    for(int i = 0; i < tar.size(); i++){
        tar[i] = tolower(tar[i]);
    }
    for(int i = 0; i < s.size(); i++){
        s[i] = tolower(s[i]);
    }
    int pos = s.find(tar);
    int ans = pos;
    if(pos == -1){
        cout << pos;
    }
    else{
        while(pos != -1){
            cnt++;
            pos = s.find(tar,pos + 1);
        }
        cout << cnt << ' ' << ans;
    }
    
    return 0;
}