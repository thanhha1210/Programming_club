#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<long long, long long> pll;
const ll MAXN = 1e15 + 9;

ll n, m, k, a, b, nm;

ll bfs(ll s, ll t, const vvll& adj, const vvll& cap, vll& p) {
    p = vll(nm + 1, -1);
    p[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, MAXN});

    while (!q.empty()) {
        ll v = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (ll to : adj[v]) {
            if (p[to] == -1 && cap[v][to] > 0) {
                p[to] = v;
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
    vll p;
    ll flow;
    while ((flow = bfs(n + m + 1, n + m + 2, adj, cap, p))) {
        ll cur = n + m + 2;
        while (cur != n + m + 1) {
            ll prev = p[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
    cout << max_flow << '\n';
}

int main() {
    cin >> n >> m >> k;
    nm = n + m + 2;
    vvll adj(nm + 1);
    vvll cap(nm + 1, vll(nm + 1, 0));
    set<pll> stroke;

    rep(i, 1, n + 1) {
        adj[n + m + 1].push_back(i);
        adj[i].push_back(n + m + 1);
        cap[n + m + 1][i] = 1;
    }
    rep(i, n + 1, n + m + 1) {
        adj[i].push_back(n + m + 2);
        adj[n + m + 2].push_back(i);
        cap[i][n + m + 2] = 1;
    }

    rep(i, 0, k) {
        cin >> a >> b;
        b += n;
        if (stroke.find({a, b}) == stroke.end()) { 
            cap[a][b] = 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
            stroke.insert({a, b});
        }
    }

    solve(adj, cap);

    for (const auto& ite : stroke) {
        long long a = ite.first;
        long long b = ite.second;
        if (cap[a][b] == 0) {
            cout << a << " " << b - n << endl;
        }
    }

    return 0;
}
