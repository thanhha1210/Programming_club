#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(auto i = j; i < n; i++)
typedef long long ll;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;

ll n, m, cnt = 0;
vvc grid;
vb visited;
const vpii adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(int i, int j) {
    grid[i][j] = '#';
     rep(k, 0, adj.size()) {
        int ni = i + adj[k].first;
        int nj = j + adj[k].second;

        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '.') {
            dfs(ni, nj);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.assign(n, vc(m));

    rep(i, 0, n) 
        rep(j, 0, m)
            cin >> grid[i][j];
    
    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == '.') {
                cnt++;
                dfs(i, j);
            }
        }
    }
    cout << cnt;
   
    return 0;
}