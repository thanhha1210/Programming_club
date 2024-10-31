#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

ll t, s, a, b, x, y;
vvll adj, cap;


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

ll find_max_flow(int source, int sink) {
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
    return max_flow;
} 


int main() {
    cin >> t; 
    while (t--) {
        adj.clear();
        cap.clear();

        cin >> s >> a >> b;
        rep(i, j, b) {
            cin >> x >> y;
        }

    }
}