#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, k) for (int i = j; i < k; i++)
typedef long long ll;

typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef pair<long long, long long> pll;
typedef vector<bool> vb;
const ll MAXN = 1e15 + 9;

ll n, m, a, b;
vvll adj, cap;
vll res;

ll bfs(ll s, ll t, vll& p) {
    p = vll(n + 1, -1);
    p[s] = -2;

    queue<pll> q;
    q.push({s, MAXN});

    while (!q.empty()) {
        ll v = q.front().first;
        ll flow = q.front().second;
        q.pop();
        for (ll to : adj[v]) {
            if (p[to] == -1 && cap[v][to] != 0) {
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

ll max_flow(ll s, ll t) {
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

void dfs(int s, vb& check, vll& path, set<pll>& stroke) {
    check[s] = true;
    path.push_back(s);
    if (s == n) return;
    for (auto v : adj[s]) {
        if (!check[v] && stroke.find({s, v}) != stroke.end()) {
            dfs(v, check, path, stroke);
            if (path.back() != n) {
                path.pop_back();
            }
        }
    }
}


void categorizeStroke(set<pll>& stroke) {
    set<pll> to_remove;
    for (const auto& ite : stroke) {
        if (cap[ite.first][ite.second] != 0) {
            to_remove.insert(ite);
        }
    }
    for (const auto& ite : to_remove) {
        stroke.erase(ite);
    }
}

void printOneLine(const vll& path) {
    cout << path.size() << '\n';
    for (auto c : path) {
        cout << c << ' ';
    }
    cout << '\n';
}

void removeStroke(vll& res, set<pll>& stroke) {
    rep(i, 0, res.size() - 1) {
        stroke.erase({res[i], res[i + 1]});
    }
}


int main() {
    cin >> n >> m;
    adj.resize(n + 1);
    cap.assign(n + 1, vll(n + 1, 0));
    set<pll> stroke;
    rep(i, 0, m) {
        cin >> a >> b;
        if (cap[a][b] == 0) {
            cap[a][b] = 1;
            adj[a].push_back(b);
            adj[b].push_back(a);
            stroke.insert({a, b});
        }
    }

    ll maxDays = max_flow(1, n);
    categorizeStroke(stroke);
    cout << maxDays << '\n';

    int d = 0;
    while (d < maxDays) {
        res.clear();
        vb check(n + 1, false);
        dfs(1, check, res, stroke);
        printOneLine(res);
        removeStroke(res, stroke);
        d++;
    }
    return 0;
}
