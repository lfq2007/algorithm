## 知识补充 ： 邻接表储存树
### 建树
```C++
cin >> n;
vector<vector<int>>adj(n,vector<int>(n));
//输入n - 1条边
for(int i = 0; i < n - 1; i++){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
```

### 遍历
```C++
vector<bool> visited(n,false);

void dfs(int u){
    visited[u] = true;
    for(int v: adj[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
}
dfs(0);

queue<int>q;
q.push(0);
visited[0] = true;

while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v: adj[u]){
        if(!visited[v]){
            visited[v] = true;
            q.push(v);
        }
    }
}
```

### 变种
#### 已知根节点
```C++
void dfs(int u, int parent){
    for(int v: adj[u]){
        if(v != parent){
            dfs(v, u);
        }
    }
}
dfs(root, -1);
```

#### 带权
存储pair<int,int>即可

#### 1-indexed
注意-1即可

## 快速读入
```c++
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

# P3379 【模板】最近公共祖先（LCA）

## 题目描述

如题，给定一棵有根多叉树，请求出指定两个点直接最近的公共祖先。

## 输入格式

第一行包含三个正整数 $N,M,S$，分别表示树的结点个数、询问的个数和树根结点的序号。

接下来 $N-1$ 行每行包含两个正整数 $x, y$，表示 $x$ 结点和 $y$ 结点之间有一条直接连接的边（数据保证可以构成树）。

接下来 $M$ 行每行包含两个正整数 $a, b$，表示询问 $a$ 结点和 $b$ 结点的最近公共祖先。

## 输出格式

输出包含 $M$ 行，每行包含一个正整数，依次为每一个询问的结果。

## 输入输出样例 #1

### 输入 #1

```
5 5 4
3 1
2 4
5 1
1 4
2 4
3 2
3 5
1 2
4 5
```

### 输出 #1

```
4
4
1
4
4
```

## 说明/提示

对于 $30\%$ 的数据，$N\leq 10$，$M\leq 10$。

对于 $70\%$ 的数据，$N\leq 10000$，$M\leq 10000$。

对于 $100\%$ 的数据，$1 \leq N,M\leq 5\times10^5$，$1 \leq x, y,a ,b \leq N$，**不保证** $a \neq b$。


样例说明：

该树结构如下：

 ![](https://cdn.luogu.com.cn/upload/pic/2282.png) 

第一次询问：$2, 4$ 的最近公共祖先，故为 $4$。

第二次询问：$3, 2$ 的最近公共祖先，故为 $4$。

第三次询问：$3, 5$ 的最近公共祖先，故为 $1$。

第四次询问：$1, 2$ 的最近公共祖先，故为 $4$。

第五次询问：$4, 5$ 的最近公共祖先，故为 $4$。

故输出依次为 $4, 4, 1, 4, 4$。


2021/10/4 数据更新 @fstqwq：应要求加了两组数据卡掉了暴力跳。


首先从例子里分析了大体的思路，即先来到同一层然后再向上找祖先，优化在于存储数据结构选择邻接表，接下来是深度和父节点的寻找，DFS和BFS都可以考虑，lambda函数的实现是这次学习的一大收获，父节点的优化在于选择倍增法，将整数进行二进制拆分，后续在两个节点同层找祖先时也是二进制拆分的思路。
另外，在两节点不同层时进行交换也是一道另一个题的思路，还要注意索引还是值的比较，并且这块判断的逻辑错误也要注意
最后是栈的优化

#### 寻找最高层
```c++
int lg = 0;
while((1 << lg) <= n) lg++;
```

#### 祖先节点和层数的预处理
```c++
stack<pair<int,int>>stk;
stk.push({s,0});
depth[0] = 0;
while(!stk.empty()){
    auto [u,p] = stk.top();
    stk.pop();

    parent[u][0] = p;
    if (u != s) depth[u] = depth[p] + 1;

    for(int k = 1; k <= lg; k++){
        if (parent[u][k - 1] != 0) {
            parent[u][k] = parent[parent[u][k - 1]][k - 1];
        }
    }

    for(int v: adj[u]){
        if (v != p) {
            stk.push({v,u});
        }
    }
}
```

#### LCA
```c++
function<int(int,int)> lca = [&](int x, int y){
    if (depth[x] < depth[y]) swap(x, y);
    int diff = depth[x] - depth[y];
    for(int k = lg; k >= 0; k--){
        if (diff & (1 << k)) {
            x = parent[x][k];
        }
    }

    if(x == y) return x;

    for(int k = lg; k >= 0; k--){
        if (parent[x][k] != parent[y][k]) {
            x = parent[x][k];
            y = parent[y][k];
        }
    }
    return parent[x][0];
};

   
```