#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const ll MAXN = 1e15 + 9;

ll n, m, a, b, c;

ll bfs(ll s, ll t, const vvll& adj, const vvll& cap, vll& parent) {
    parent = vll(n + 1, -1);
    parent[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, MAXN});

    while (!q.empty()) {
        ll v = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (ll to : adj[v]) {
            if (parent[to] == -1 && cap[v][to] > 0) {
                parent[to] = v;
                ll new_flow = min(flow, cap[v][to]);
                if (to == t) {
                    return new_flow;
                }
                q.push({to, new_flow});
            }
        }
    }
    return 0;
}

void solve(const vvll& adj, vvll& cap) {
    ll max_flow = 0;
    vll parent;
    ll flow;
    while ((flow = bfs(1, n, adj, cap, parent))) {
        ll cur = n;
        while (cur != 1) {
            ll prev = parent[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
    cout << max_flow << '\n';
}

int main() {
    cin >> n >> m;
    vvll adj(n + 1);
    vvll cap(n + 1, vll(n + 1, 0));
    rep(i, 0, m) {
        cin >> a >> b >> c;
        if (a == b) continue;
        if (cap[a][b] == 0) {
            cap[a][b] = c;
            adj[a].push_back(b);
            adj[b].push_back(a); 
        }
        else {
            cap[a][b] += c;
        }
       
    }
    solve(adj, cap);
    return 0;
}
