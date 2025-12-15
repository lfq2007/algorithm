#include<bits/stdc++.h>
using namespace std;
int sdk[11][11];
bool r[11][11], c[11][11], grid[11][11];

void _out(){
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cout << sdk[i][j] << ' ';
        }
        cout << '\n';
    }
    exit(0);
}

void dfs(int x, int y) {
    if (sdk[x][y] != 0) {
        if (x == 9 && y == 9) _out();
        else if(y == 9) {
            dfs(x + 1, 1);
        }
        else{
            dfs(x, y + 1);
        }
    }
    else{
        for (int i = 1; i <= 9; i++) {
            if ((!r[x][i]) && (!c[y][i]) && (!grid[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i])) {
                sdk[x][y] = i;
                r[x][i] = c[y][i] = grid[(x - 1) / 3 * 3 + (y - 1) / 3 + 1][i] = true;
                if (x == 9 && y == 9) _out();
                else if(y == 9) {
                    dfs(x + 1, 1);
                }
                else{
                    dfs(x, y + 1);
                }
                sdk[x][y] = 0;
                r[x][i] = c[y][i] = grid[(x-1)/3*3+(y-1)/3+1][i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int tmp;
            cin >> tmp;
            if (tmp != 0) {
                r[i][tmp] = true;
                c[j][tmp] = true;
                grid[(i - 1) / 3 * 3+(j - 1) / 3 + 1][tmp] = true;
            }
            sdk[i][j] = tmp;
        }
    }
    dfs(1, 1);
    return 0;
}
/*
行列判断：用两个二维bool数组标记
bool p[][] l[][]
如果在1行3列填入数字2
p[1][2] = l[3][2] = true;

对于方阵:给出数学表达式
方阵序号 = （行数 - 1） / 3 * 3 + （列数 - 1）/ 3 + 1 
*/