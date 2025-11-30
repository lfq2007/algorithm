/*
1 str：后接插入，在文档后面插入字符串 str，并输出文档的字符串；
2 a b：截取文档部分，只保留文档中从第 a 个字符起 b 个字符，并输出文档的字符串；
3 a str：插入片段，在文档中第 a 个字符前面插入字符串 str，并输出文档的字符串；
4 str：查找子串，查找字符串 str 在文档中最先的位置并输出；如果找不到输出 −1。
第一行输入一个正整数 q，表示操作次数。

第二行输入一个字符串 str，表示最开始的字符串。

第三行开始，往下 q 行，每行表示一个操作，操作如题目描述所示。
4
ILove
1 Luogu
2 5 5
3 3 guGugu
4 gu

ILoveLuogu
Luogu
LuoguGugugu
3
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    int op;
    string s;
    cin >> s;
    while(q--){
        cin >> op;
        if(op == 1){
            string subs;
            cin >> subs;
            s = s + subs;
            cout << s << endl;
        }
        else if(op == 2){
            int a, b;
            cin >> a >> b;
            s = s.substr(a,b);
            cout << s << endl;
        }
        else if(op == 3){
            int a;
            string subs;
            cin >> a;
            cin >> subs;
            s.insert(a,subs);
            cout << s << endl;
        }
        else{
            string subs;
            cin >> subs;
            int pos = s.find(subs);
            cout << pos << endl;
        }
    }
    return 0;
}