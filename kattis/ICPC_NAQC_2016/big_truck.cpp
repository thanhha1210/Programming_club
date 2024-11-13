#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

const ll INF = 1e9 + 7;
ll n, m;
vll a, dp, d;
vvpll adj;

void dijkstra() {
    priority_queue<pll, vpll, greater<pll>> pq;
    d[1] = 0; dp[1] = a[1];
    pq.push({0, 1});
    while (!pq.empty()) {
        ll v = pq.top().second, dv = pq.top().first;
        pq.pop();
        if (d[v] != dv) continue;
        for (auto edge : adj[v]) {
            ll to = edge.first, len = edge.second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                dp[to] = dp[v] + a[to];
                pq.push({d[to], to});
            }
            else if (d[v] + len == d[to] && dp[to] < dp[v] + a[to]) {
                dp[to] = dp[v] + a[to];
                pq.push({d[to], to});
            }
        }
    }
     
    if (d[n] == INF) {
        cout << "impossible\n";
    }
    else {
        cout << d[n] << ' ' << dp[n] << '\n';
    }
}

int main() {
    cin >> n;
    a.resize(n + 1);
    dp.assign(n + 1, 0);
    d.assign(n + 1, INF);
    adj.resize(n + 1, vpll());

    rep(i, 1, n + 1) cin >> a[i];   // a[i] hold value of i
    cin >> m;
    ll u, v, c;
    rep(i, 0, m) {
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    dijkstra();
}