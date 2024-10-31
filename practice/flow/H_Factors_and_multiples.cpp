#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

ll t, n, m, x, res, sink, source;
vll a, b, ans;
vvll cap, adj;

ll MAX_N = 1e9 + 7;

ll bfs(ll s, ll t, vll& p) {
    p.assign(n + m + 2, -1);
    p[s] = -2;

    queue<pair<ll, ll>> q;
    q.push({s, MAX_N});

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

void find_max_flow(int source, int sink) {
    ll max_flow = 0, flow;
    vll p;
    while ((flow = bfs(source, sink, p))) {
        ll cur = sink;
        while (cur != source) {
            ll prev = p[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
    ans.push_back(max_flow);
} 

void createGraph() {
    rep(i, 0, a.size()) {
        cap[source][i] = 1;
        adj[source].push_back(i);
        adj[i].push_back(source);
    }

    rep (i, 0, b.size()) {
        cap[i + n][sink] = 1;
        adj[sink].push_back(i + n);
        adj[i + n].push_back(sink); 
    }

    rep(i, 0, a.size()) {
        rep(j, 0, b.size()) {
            if ((a[i] != 0) && (b[j] % a[i] == 0)) {
                cap[i][j + n] = 1;
                adj[i].push_back(j + n);
                adj[j + n].push_back(i);
            }
            else if (a[i] == 0 && b[j] == 0) {
                cap[i][j + n] = 1;
                adj[i].push_back(j + n);
                adj[j + n].push_back(i);
            }
        }
    }
}

void solve() {
    rep(i, 0, ans.size()) {
        cout << "Case " << (i + 1) << ": " << ans[i] << endl;
    }
}

int main() {
    cin >> t;
    rep(d, 1, t + 1) {
        res = 0;
        a.clear();
        b.clear();
        cap.clear();
        adj.clear();

        cin >> n;
        rep(i, 0, n) {
            cin >> x; 
            a.push_back(x);
        }

        cin >> m;
        rep(i, 0, m) {
            cin >> x;
            b.push_back(x);
        }

        adj.resize(n + m + 2);
        cap.assign(n + m + 2, vll(n + m + 2, 0));

        source = m + n;
        sink = m + n + 1;

        // a -> 0 : n - 1; b -> n : m + n - 1
        createGraph();
        find_max_flow(source, sink);
    }

    solve();

    return 0;
}
