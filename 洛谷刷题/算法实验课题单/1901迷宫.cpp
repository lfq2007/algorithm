#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m;
char grid[MAXN][MAXN];
int color[MAXN][MAXN]; 
int compSize[MAXN * MAXN]; 
int currentColor = 0;

void dfs(int x, int y, int col) {
    color[x][y] = col;
    compSize[col]++;
    
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        

        if (nx < 1 || nx > n || ny < 1 || ny > n) continue;
        
        if (grid[nx][ny] == grid[x][y]) continue;
        
        if (color[nx][ny] != 0) continue;
        
        dfs(nx, ny, col);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (color[i][j] == 0) {
                currentColor++;
                dfs(i, j, currentColor);
            }
        }
    }
    while (m--) {
        int x, y;
        cin >> x >> y;
        cout << compSize[color[x][y]] << '\n';
    }
    
    return 0;
}