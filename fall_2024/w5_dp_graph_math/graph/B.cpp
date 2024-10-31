#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<pair<long long, long long>>> vvpll;
const ll INF = 1e12 + 7;

ll n, m, a, b, c;
vll dis, p, res;
vb check;
vvpll adj;

void dijkstra() {
    dis[0] = 0; dis[1] = 0;
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, 1});
    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        check[v] = true;
        pq.pop();

        if (d != dis[v]) {
            continue;
        }

        for (auto to : adj[v]) {
            ll u = to.first, k = to.second;
            if (dis[u] > k + d) {
                dis[u] = k + d;
                p[u] = v;
                pq.push({dis[u], u});
            }
        }
    }
}

void track_back() {
    if (!check[n]) {
        cout << -1;
        return;
    }
    int k = n;
    while (k != 1) {
        res.push_back(k);
        k = p[k];
    }
    res.push_back(1);
    reverse(res.begin(), res.end());
    rep(i, 0, res.size()) {
        cout << res[i] << ' ';
    }
    
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vpll());
    dis.assign(n + 1, INF);
    check.assign(n + 1, false);
    p.assign(n + 1, -1);
    rep(i, 0, m) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    dijkstra();
    track_back();

}