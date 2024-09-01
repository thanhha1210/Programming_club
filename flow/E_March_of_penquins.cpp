#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

struct Point {
    int x, y, penNum, maxJump;
    double distance(Point o) {
        return sqrt(1.0 * ((o.x - x) * (o.x - x) + (o.y - y) * (o.y - y)));
    }
};

int t, n, pen;
float d;
vector<Point> points;
vvll adj;
vvll cap;

void createPoint() {
    rep(i, 0, points.size()) {
        cap[2 * n][i] = points[i].penNum; // Source to floe
        adj[2 * n].push_back(i);
        adj[i].push_back(2 * n);

        cap[i][i + n] = points[i].maxJump; // Floe to out-floe
        adj[i].push_back(i + n);
        adj[i + n].push_back(i);

        rep(j, 0, points.size()) {
            if (i != j && points[i].distance(points[j]) <= d) {
                cap[i + n][j] = points[i].maxJump; // Out-floe to floe
                adj[i + n].push_back(j);
                adj[j].push_back(i + n);
            }
        }
    }
}

ll bfs(ll s, ll t, vll& p) {
    p.assign(adj.size(), -1);
    p[s] = -2;
    queue<pair<ll, ll>> q;
    q.push({s, LLONG_MAX});

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

ll maxFlow(int s, int t) {
    ll max_flow = 0;
    vll p;
    ll flow;
    while ((flow = bfs(s, t, p))) {
        ll cur = t;
        while (cur != s) {
            ll prev = p[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
    return max_flow;
}

void solve() {
    vll res;
    rep(i, 0, n) {
        vvll tempCap = cap; // hold the original capacity vector
        if (maxFlow(2 * n, i) >= pen) {
            res.push_back(i);
        }
        cap = tempCap;  // restore the original capacity vector
    }

    if (res.empty()) {
        cout << -1 << endl;
    } 
    else {
        rep(i, 0, res.size()) {
            if (i != res.size() - 1)
                cout << res[i] << " ";
            else 
                cout << res[i];
        }
        cout << endl;
    }
}

int main() {
    cin >> t;

    while (t--) {
        cin >> n >> d;
        pen = 0;
        points.clear();
        adj.clear();
        cap.clear();

        // source -> 2 * n
        points.resize(n);
        adj.resize(2 * n + 1);
        cap.assign(2 * n + 1, vll(2 * n + 1, 0));

        rep(i, 0, n) {
            cin >> points[i].x >> points[i].y >> points[i].penNum >> points[i].maxJump;
            pen += points[i].penNum;
        }

        createPoint();
        solve();
    }
    return 0;
}
