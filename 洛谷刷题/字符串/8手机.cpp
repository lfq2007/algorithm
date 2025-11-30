#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int cnt = 0;
    int nums[26] = {
        1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4
    };
    for(int i = 0; i < s.size(); i++){
        if(s[i] == ' ') cnt++;
        else{
            cnt += nums[s[i] - 'a'];
        }//这里最好还是判断一下，因为有'/r和/n'
    }
    cout << cnt;
    return 0;
}