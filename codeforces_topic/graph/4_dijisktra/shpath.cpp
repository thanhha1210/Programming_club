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
typedef unordered_map<string, ll> ssl;

const long long INF = 1e9;
ll t, n, m, a, b, c, r, d = 0, cnt = 0;
vvpll adj;
vll dist;
string c_name, s1, s2;
ssl name;

void dijkstra(ll s, ll e) {
    dist.assign(n + 1, INF);
    dist[s] = 0;
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll dv = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        if (dv != dist[v]) {
            continue;
        }

        if (v == e) {
            break;
        }

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll cost = edge.second;
            if (dist[to] > dv + cost) {
                dist[to] = dv + cost;
                pq.push({dist[to], to});
            }
        }
    } 

}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        name.clear();
        adj.assign(n + 1, vpll());

        rep(i, 1, n + 1) {
            cin >> c_name >> m;
            name[c_name] = i;

            rep(j, 0, m) {
                cin >> b >> c;
                adj[i].push_back({b, c});
            }
        }

        cin >> r;
        rep(i, 0, r) {
            cin >> s1 >> s2;
            ll i1 = name[s1];
            ll i2 = name[s2];
            dijkstra(i1, i2);
            cout << dist[i2] << '\n';
        }

    }
}
