#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;

const vpii op = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int h, w, cnt, maxx;
char c;
vvi grid;
vvi memo;

bool isValid(int x, int y) {
    return (x >= 0 && x < h && y >= 0 && y < w);
}

int dfs(int x, int y) {
    if (memo[x][y] != -1) return memo[x][y];
    
    int maxPath = 1; // At least the path length is 1 (itself)
    for (auto dir : op) {
        int x1 = x + dir.first;
        int y1 = y + dir.second;
        if (isValid(x1, y1) && grid[x1][y1] == grid[x][y] + 1) {
            maxPath = max(maxPath, 1 + dfs(x1, y1));
        }
    }
    return memo[x][y] = maxPath;
}

int main() {
    cnt = 1;
    while (cin >> h >> w) {
        if (h == 0 && w == 0) break;
        
        grid.assign(h, vi(w, 0));
        memo.assign(h, vi(w, -1));
        
        rep(i, 0, h) {
            rep(j, 0, w) {
                cin >> c;
                grid[i][j] = c - 'A' + 1;
            }
        }
        
        maxx = 0;
        rep(i, 0, h) {
            rep(j, 0, w) {
                if (grid[i][j] == 1) {
                    maxx = max(maxx, dfs(i, j));
                }
            }
        }
        
        cout << "Case " << cnt++ << ": " << maxx << '\n';
    }
    return 0;
}
