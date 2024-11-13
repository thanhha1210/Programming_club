#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<pair<long long, long long>>> vvpll;

const long long INF = 1e9;
ll t, n, m, a, b, c, cnt = 0;
vvpll adj;
vll d;


void dijkstra(ll s, ll e) {
    d.assign(n + 1, INF);
    d[s] = 0;

    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll v = pq.top().second;
        ll dv = pq.top().first;
        pq.pop();

        if (v == e) {
            break;
        }
        if (d[v] != dv) {
            continue;
        }

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }
    if (d[e] == INF) {
        cout << "NO\n";
    }
    else {
        cout << d[e] << '\n';
    }
   
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        adj.assign(n + 1, vpll());
        rep(i, 0, m) {
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        cin >> a >> b;
        dijkstra(a, b);
    }
}
