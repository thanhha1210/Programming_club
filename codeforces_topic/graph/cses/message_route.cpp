#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;

ll n, m, a, b, cnt = 0;
vvll adj;
vll d, p, res;

void bfs(ll s) {
    queue<ll> q;
    q.push(s);
    d[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto to : adj[v]) {
            if (d[to] == -1) {
                d[to] = d[v] + 1;
                p[to] = v;
                q.push(to);
            }
        }
    }
}

void backtrack() {
    ll k = n;
    while (k != 1) {
        res.push_back(k);
        k = p[k];
    }
    res.push_back(1);
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    rep(i, 0, res.size())
        cout << res[i] << " ";
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll(0));
    d.assign(n + 1, -1);
    p.assign(n + 1, -1);
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    if (d[n] == -1) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        backtrack();
    }
 
}