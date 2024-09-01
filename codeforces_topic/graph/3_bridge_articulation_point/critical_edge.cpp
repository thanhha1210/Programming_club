#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<long long, long long>> vpll;

const long long INF = 1e9;
ll t, n, m, a, b, d = 0, cnt = 0;
vvll adj;
vll tin, low;
vb visited;
vpll bridges;

void dfs(long long v, long long p = -1) {
    visited[v] = true;
    tin[v] = low[v] = cnt++;
    
    for (long long to : adj[v]) {
        if (to == p) {
            continue;
        }
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({min(v, to), max(v, to)});
            }
        }
    }

}


void output() {
    cout << "Caso #" << d << '\n';
    if (bridges.empty()) {
        cout << "Sin bloqueos" << '\n';
    }
    else {
        sort(bridges.begin(), bridges.end());
        cout << bridges.size() << '\n';
        for (auto& b : bridges) {
            cout << b.first << ' ' << b.second << '\n';
        }
    }
}


int main() {
    cin >> t;
    while (t--) {
        d++;
        cin >> n >> m;
        adj.clear();
        bridges.clear();
        tin.assign(n + 1, INF);
        low.assign(n + 1, INF);
        visited.assign(n + 1, false);
        adj.resize(n + 1);
        cnt = 0;
        
        rep(i, 0, m) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        rep(i, 1, n + 1) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
        output();
    }
    return 0;
}
