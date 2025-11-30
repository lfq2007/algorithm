#include<bits/stdc++.h>
using namespace std;
int main(){
    int x ,n, ans = 0;
    cin >> x >> n;
    vector<int>coin(n);
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    }
    sort(coin.begin(),coin.end());
    if(coin[0] != 1){
        cout << -1;
        return 0;
    }
    int sum = 0;
    int i ;
    while(sum < x){
        for(i = n - 1; i >= 0; i--){
            if (coin[i] <= sum + 1) {
                break;
            }
        }
        ans++;
        sum += coin[i];
    }
/*    else{
        int pos = coin.size() - 1;
        while(pos >= 0){
            int cnt = x / coin[pos];
            int res = x % coin[pos];
            if(pos != 0 && res == 0){
                cnt -= 1;
                res = coin[pos];
            }
            x = max(res,coin[pos] - 1);
            pos--;
            ans += cnt;
        }
*/
//    int pos = coin.size() - 1;
//    int cnt = x / coin[pos];
//    int res = x % coin[pos];
//    x = res;
//    pos--;
//    ans += cnt;
//    贪心策略有误,本来的思考是如果能凑出1-5，那就可以凑出11 - 15，所以倒过来取余，
//但是如果最大的两个差值不那么大，选大的反而导致前面用的多比如用1 4 5凑1-7
    cout << ans;
    
    return 0;
}