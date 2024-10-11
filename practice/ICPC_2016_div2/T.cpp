#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
int n, m, cnt = 0, l, r, u, d;
vvc grid;
vvb check;

void dfs(int i, int j) {
    check[i][j] = true;
    l = j - 1, r = j + 1, u = i - 1, d = i + 1;
    if (l >= 0 && !check[i][l] && (grid[i][l] == 'L' || grid[i][l] == 'C')) {
        grid[i][l] = 'L';
        dfs(i, l);
    }
    if (r < m && !check[i][r] && (grid[i][r] == 'L' || grid[i][r] == 'C')) {
        grid[i][r] = 'L';
        dfs(i, r);
    }
    if (u >= 0 && !check[u][j] && (grid[u][j] == 'L' || grid[u][j] == 'C')) {
        grid[u][j] = 'L';
        dfs(u, j);
    }
    if (d < n && !check[d][j] && (grid[d][j] == 'L' || grid[d][j] == 'C')) {
        grid[d][j] = 'L';
        dfs(d, j);
    }  
}

int main() {
    cin >> n >> m;
    grid.assign(n, vc(m));
    check.assign(n, vb(m, false));
    rep(i, 0, n) 
        rep(j, 0, m)
            cin >> grid[i][j];

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == 'L' && !check[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}