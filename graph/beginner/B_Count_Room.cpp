#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

ll n, m;
vvc grid;


void dfs(int i, int j) {
    grid[i][j]='#';
    if (j + 1 < m && grid[i][j + 1] == '.') {
        dfs(i, j + 1);
    }
    if (j - 1 > 0 && grid[i][j - 1] == '.') {
        dfs(i, j - 1);
    }
    if (i + 1 < n && grid[i + 1][j] == '.') {
        dfs(i + 1, j);
    }
    if (i - 1 > 0 && grid[i - 1][j] == '.') {
        dfs(i - 1, j);
    }
}


void solve() {
    int cnt = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == '.') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt << '\n';
}

int main() {
    cin >> n >> m;
    grid.assign(n , vc(m));

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
        }
    }
    
    solve();

}