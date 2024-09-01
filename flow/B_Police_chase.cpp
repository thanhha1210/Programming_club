#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<long long, long long>> vpll;

const ll MAXN = 1e15 + 9;

ll n, m, a, b, c, max_flow;
vvll adj, cap;
vb checkReach;
vpll res;

ll bfs(ll s, ll t, vll& p) {

    checkReach.assign(n + 1, false);

    p.assign(n + 1, -1);
    p[s] = -2;

    queue<pair<ll, ll>> q;
    q.push({s, MAXN});

    while (!q.empty()) {
        ll v = q.front().first;
        ll flow = q.front().second;

        checkReach[v] = true;

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

void find_max_flow() {
    max_flow = 0;
    int flow;
    vll p;
    while ((flow = bfs(1, n, p))) {
        ll cur = n;
        while (cur != 1) {
            ll prev = p[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
}

void print_output() {
    rep(i, 1, n + 1) {
        if (checkReach[i]) {
            for (auto x : adj[i]) {
                if (!checkReach[x]) {
                    res.push_back({i, x});
                }
            }
        }
    }

    cout << res.size() << '\n';

    rep(i, 0, res.size()) {
        cout << res[i].first << ' ' << res[i].second << '\n';
    }

}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll());
    cap.assign(n + 1, vll(n + 1, 0));

    rep(i, 0, m) {
        cin >> a >> b;
        if (cap[a][b] == 0) {
            adj[a].push_back(b);
            adj[b].push_back(a);
            cap[a][b] = 1;
            cap[b][a] = 1;
        }
    }

    find_max_flow();

    print_output();


    return 0;
}