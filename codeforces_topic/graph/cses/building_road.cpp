#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;

ll n, m, a, b, cnt = 0;
vvll adj;
vll res; 
vb visited;

void dfs(ll s) {
    visited[s] = true;
    for (auto v : adj[s]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll(0));
    visited.assign(n + 1, false);
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i, 1, n + 1) {
        if (!visited[i]) {
            res.push_back(i);
            dfs(i);
        }
    }
    cout << res.size() - 1 << '\n';
    rep(i, 1, res.size()) {
        cout << res[0] << " " << res[i] << "\n";
    }
}