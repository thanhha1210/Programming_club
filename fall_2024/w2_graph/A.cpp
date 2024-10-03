#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<bool> vb;
typedef vector<vector<long long>> vvll;

ll n, m, a, b;
vvll adj;
vb visited;
vll res;

void dfs(int s) {
    visited[s] = true;
    for (auto v : adj[s]) {
        if (!visited[v])
            dfs(v);
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll());
    visited.assign(n + 1, false);

    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    rep(i, 1, n + 1) {
        if (!visited[i]) {
            res.push_back(i);
        }
    }
    if (res.size() == 0) {
        cout << "Connected";
    }
    else {
        rep(i, 0, res.size()) {
            cout << res[i] << '\n';
        }
    }
    return 0;
}