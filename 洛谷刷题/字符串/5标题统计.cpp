//输入格式
//输入文件只有一行，一个字符串 s。

//输出格式
//输出文件只有一行，包含一个整数，即作文标题的字符数（不含空格和换行符）。
#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int ans = 0;
    for(char c : s){
        if(c != ' '){
            ans++;
        }
    }
    cout << ans;
    return 0;
}
//int main(){
//    char c;
//    int ans = 0;
//    for(int i = 0; i < 5; i++){
//        if(cin >> c) ans++;
//    }
//    cout << ans;
//    return 0;
//}

//isalpha isalnum isdigit isupper islower