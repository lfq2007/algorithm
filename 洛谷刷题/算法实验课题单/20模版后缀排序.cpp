#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int CHARSET = 128;
char s[MAXN];
int sa[MAXN], rk[MAXN], new_rk[MAXN], buc[MAXN];
int sec[MAXN];
/*
注意先理解总体思想：
我们首先比较第一位，
怎么比较第二位呢，我们比较前两位，第一位已经知道了，第二位就是第一位偏移1，如果没法偏移说明足够短
现在来比较前四位，前两位知道了，后两位就是前两位偏移2
rk[i]不断更新，表示前几位的排名，那么rk[i + k]决定着新的rk
*/
//sa[i]排名为i的后缀的起始位置
//rk[i]起始位置为i的后缀的当前排名
//sec[i]临时数组，用于第二关键字的排序
void build_sa(int n){
    int m = CHARSET;
    memset(buc, 0, sizeof(int) * m);
    for (int i = 0; i < n; i++) {
        buc[(int)s[i]]++;
    }
    for (int i = 1; i < m; i++) {
        buc[i] += buc[i - 1];
    }
    //频次数组转化为前缀和数组
    for (int i = n - 1; i >= 0; i--) {
        sa[--buc[(int)s[i]]] = i;//buc[]数组其实可以看做一个排序，键是字符
        //值是排名，
        //这里sa做一个映射，
        //键是排名 值是字符位置，方便后面的rk的处理
    }

    rk[sa[0]] = 0;
    for (int i = 1; i < n; i++) {
        rk[sa[i]] = rk[sa[i - 1]] + (s[sa[i]] != s[sa[i - 1]]);
    }

    for (int k = 1; k < n; k <<= 1) {
        int p = 0;
        
        // 先放没有第二关键字的（第二关键字为空）
        for (int i = n - k; i < n; i++) {
            sec[p++] = i;
        }
        
        // 再放有第二关键字的，按第二关键字顺序
        for (int i = 0; i < n; i++) {
            if (sa[i] >= k) {
                sec[p++] = sa[i] - k;
            }
        }

        int max_rank = max(n, m);
        memset(buc, 0, sizeof(int) * max_rank);
        for (int i = 0; i < n; ++i) ++buc[rk[i]];
        for (int i = 1; i < max_rank; ++i) buc[i] += buc[i - 1];  

        for (int i = n - 1; i >= 0; i--) {
            int idx = sec[i];
            sa[--buc[rk[idx]]] = idx;
            //对比，这里的buc是基于rk排序的
        }   
        
        // 3. 计算新的排名
        new_rk[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            int cur = sa[i], prev = sa[i - 1];
            // 比较当前后缀和上一个后缀的两个关键字
            if (rk[cur] == rk[prev] && 
                (cur + k < n ? rk[cur + k] : -1) == (prev + k < n ? rk[prev + k] : -1)) {
                new_rk[cur] = new_rk[prev];
            } else {
                new_rk[cur] = new_rk[prev] + 1;
            }
        }
        
        // 更新rk数组
        swap(rk, new_rk);
        
        int t = rk[sa[n - 1]];
        // 如果所有后缀排名已经不同，提前结束
        if (t == n) {
            break;
        }
    
    }




}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    int n = strlen(s);
    
    build_sa(n);
    
    // 输出结果（位置从1开始）
    for (int i = 0; i < n; i++) {
        cout << sa[i] + 1;
        if (i < n - 1) cout << " ";
    }
    cout << endl;    
    

    return 0;
}


    /*
    举个例子：
    banana
    0 banana
    1 anana
    2 nana
    3 ana
    4 na
    5 a
    s[0] = b, s[1] = a, s[2] = n, s[3] = a, s[4] = n, s[5] = a;
    buc[a] = 3, buc[b] = 4, buc[n] = 6;


    sa[2] = 5, sa[5] = 4, sa[1] = 3, sa[4] = 2, sa[0] = 1, sa[3] = 0,
    buc[a] = 0, buc[b] = 3, buc[n] = 4; 
    此时，sa就是[1, 3, 5, 0, 2, 4]对应a a a b n n且保证了顺序稳定
    0 anana
    1 ana
    2 a
    3 banana
    4 nana
    5 na
    rk = [1, 0, 2, 0, 2, 0]对应b, a, n, a, n, a

    sec = [5, 0, 2, 4, 1, 3],其中如果不是>= 1表示不能成为后缀的开头
    
    buc[0] = 2, buc[1] = 3, buc[2] = 5
    buc = [2,3,5]

    sa = [5, 1, 3, 0, 2, 4]
    */