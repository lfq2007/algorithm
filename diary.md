# 3
## 3.1
### 1unite
```c++
bool unite(int x, int y) {
    //int x = find(x);
    //int y = find(y);
    if (fa[x] != fa[y]) {
        fa[y] = fa[x];
        //return true;
    }
    return false;
}

```

### 2重载<
```c++
bool operator<(const &Edge other) const{
    return w < w.other;
}
/*
注意学习这里,&???
*/

bool cmp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}
```

### 3快速幂
```c++
long long qiuck_pow(long long  a, long long b, int m) {
    long long sum = 0;//这里是乘，所以是1
    a %= m;
    while (b) {
        if (b & 1) {
            sum = (sum + a) % m;//sum = (sum * a) % m;
        }
        a = (a * a) % m;
        //b >>= 1; 不要忘了这一步；
    }
    return sum;
}
/*
要做的是a的b次方mod m,首先要对a取模，然后剩余思路是依次去用a平方，a立方等，实现方法是
b做二进制分解，a = a * a；
*/
```

### 4跳石头
```c++
/*
题目：给出总长度l，石头数n，可用步数m，给出n个石头到起点的距离，最大化两个相邻石头间的最小间距
思路首先来自最大化最小值，另一个是ans最大值是跟随m单调变化的，如果m很大，完全可以达到l，如果m变大，则小的ans至少不会变小
本来是给定步数求间距，现在卡死间距求步数，就不用在意顺序了，只需要小于间距就挪动即可
*/
vector<int>dis(n + 1, 0);

int check(int mind) {
    int res = 0;
    int i = 0;
    while (i < n) {
        if (dis[i + 1] - dis[i] < mind) {
            res++;
        }
        //i++;注意
    }
    if (l - dis[n] < mind) {
        res++;
    }
    return res;
}

int main() {
    int le = 0, r = l, mid;
    while (r > le) {
        mid = (r - le) / 2 + le;
        if (check(mid) > m) {
            r = mid;
        } 
        else if (check(mid) < m) {
            l = mid + 1;
        }
        else{
            return mid;
        }
    }
}
//这里的写法还是合并<=，然后记录ans更合适
```

## 3.3
### 1上取整
```c++
t += (p + k - 1) / k;
```
### 2引用
```c++
vector<int>&piles,改变会修改数组值
```

### 3数组最值
```c++
*max_element(piles.begin(), piles.end())
```

### 4二分的答案
```c++
return l;
```

## 3.5

### 1数组求和
```c++
accumulate(nums.begin(), nums.end(), 0);
```

### 2二分左端点
本质是可能值，所以要区别是0还是1