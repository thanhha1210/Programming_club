#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;

const int MAXN = 1e5;

int bfs(int s, int t, const vvi& adj, const vvi& cap, vi& p) {
    p = vi(n + 1, -1);
    p[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, MAXN});

    while (!q.empty()) {
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int to : adj[v]) {
            if (p[to] == -1 && cap[v][to] > 0) {
                p[to] = v;
                int new_flow = min(flow, cap[v][to]);
                if (to == t) {
                    return new_flow;
                }
                q.push({to, new_flow});
            }
        }
    }
    return 0;
}

void solve(const vvi& adj, vvi& cap) {
    int max_flow = 0;
    vi p;
    int flow;
    while ((flow = bfs(1, n, adj, cap, p))) {
        int cur = n;
        while (cur != 1) {
            int prev = p[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
    cout << max_flow << '\n';
}

int main() {
    int n, m, a, b, res = 0;

    cin >> n >> m;

    vvi adj(n + 1);  // take adjacent vertex
    vvi cap(n + 1, vi(n + 1, 0));
    vpii stroke(m);

    rep(i, 0, m) {
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
        stroke[i] = make_pair(a, b);
    }
    check(1, b, adj, cap);

    rep(i, 0, m) {
        int a = stroke[i].first;
        int b = stroke[i].second;
        if (cap[a][b] == 0 || cap[b][a] == 0) {
            res++;
        }
    }
    cout << res;

}