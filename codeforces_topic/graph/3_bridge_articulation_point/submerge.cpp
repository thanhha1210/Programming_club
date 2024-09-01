#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<long long, long long>> vpll;
typedef set<long long> sll;

const long long INF = 1e9;
ll t, n, m, a, b, cnt = 0;
vvll adj;
vll tin, low;
vb visited;
sll articulation_points;

void dfs(ll v, ll p = -1) {
    visited[v] = true;
    low[v] = tin[v] = cnt++;
    int children = 0;
    
    for (auto to : adj[v]) {
        if (to == p)
            continue;
        if (visited[to]) {
            low[v] = min(tin[to], low[v]);
        }
        else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p != -1) {
                articulation_points.insert(v);
            }
            children++;
        }
    }

    if (p == -1 && children > 1) {
        articulation_points.insert(v);
    }
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        cnt = 0;
        articulation_points.clear();
        tin.assign(n + 1, -1);
        low.assign(n + 1, -1);
        visited.assign(n + 1, false);
        adj.assign(n + 1, vll());

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        cout << articulation_points.size() << '\n';
    }
}
