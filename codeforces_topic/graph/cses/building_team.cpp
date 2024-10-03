#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;

ll n, m, a, b, cnt = 0;
vvll adj;
vll d;
vb visited;
bool check = true;

void bfs(ll s) {
    visited[s] = true;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto u : adj[v]) {
            if (!visited[u]) {
                d[u] = d[v] + 1;               
                visited[u] = true;
                q.push(u);
            }
        }      
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll());
    visited.assign(n + 1, false);
    d.assign(n + 1, 0);
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    rep(i, 1, n + 1) {
        if (!visited[i]) {
            bfs(i);
        }
    }
    rep(i, 1, n + 1) {
        rep(j, 0, adj[i].size()) {
            if ((d[i] + d[adj[i][j]]) % 2 == 0)  {
                check = false;
                break;
            }
        }
    }
    if (!check) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        rep(i, 1, 1 + n) {
            if (d[i] % 2 == 0) 
                cout << 1 << " ";
            else 
                cout << 2 << " ";
        }
    }
 
}