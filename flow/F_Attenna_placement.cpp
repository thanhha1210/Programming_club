#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


int t, n, m, source, sink;
const ll MAX_N = 1e9;
char x;

vll white, black;
set<ll> find_black;
vvll cap, adj;


ll bfs(int s, int t, vll& p) {
    p.assign(n * m + 2, -1);
    p[s] = -2;

    queue<pair<ll, ll>> q;
    q.push({s, MAX_N});

    while (!q.empty()) {
        int v = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (auto to : adj[v]) {
            if (p[to] == -1 && cap[v][to] > 0) {
                p[to] = v;
                ll new_flow = (flow < cap[v][to] ? flow : cap[v][to]);
                if (to == t) {
                    return new_flow;
                }
                q.push({to, new_flow});
            }
        }
    }
    return 0;

}

void maxFlow() {
    ll max_flow = 0, flow;
    vll p;

    while (flow = bfs(source, sink, p)) {
        ll cur = sink;
        while (cur != source) {
            ll prev = p[cur];
            cap[prev][cur] -= flow;
            cap[cur][prev] += flow;
            cur = prev;
        }
        max_flow += flow;
    }
    cout << white.size() + black.size() - max_flow << '\n';

}




void createGraph() {
    rep(i, 0, white.size()) {
        cap[source][white[i]] = 1;
        adj[source].push_back(white[i]);
        adj[white[i]].push_back(source);
    }
    rep(i, 0, black.size()) {
        cap[black[i]][sink] = 1;
        adj[sink].push_back(black[i]);
        adj[black[i]].push_back(sink);
    }

    rep(i, 0, white.size()) {
        int c = white[i];
        if (find_black.find(c - 1) != find_black.end()) {
            cap[c][c - 1] = 1;
            adj[c].push_back(c - 1);
            adj[c - 1].push_back(c);
        }
        if (find_black.find(c + 1) != find_black.end()) {
            cap[c][c + 1] = 1;
            adj[c].push_back(c + 1);
            adj[c + 1].push_back(c);
        }
        if (find_black.find(c - m) != find_black.end()) {
            cap[c][c - m] = 1;
            adj[c].push_back(c - m);
            adj[c - m].push_back(c);
        }
        if (find_black.find(c + m) != find_black.end()) {
            cap[c][c + m] = 1;
            adj[c].push_back(c + m);
            adj[c + m].push_back(c);
        }
    }

}

int main() {

    cin >> t;

    while(t--) {
        cin >> n >> m;
        source = n * m;
        sink = n * m + 1;

        white.clear();
        black.clear();
        cap.clear();
        adj.clear();
        find_black.clear();

        cap.assign(n * m + 2, vll(n * m + 2, 0));
        adj.resize(n * m + 2);

        rep(i, 0, n) {
            rep(j, 0, m) {
                cin >> x;
                if (x == '*') {
                    if ((i + j) % 2 == 0)
                        white.push_back(i * m + j);
                    else {
                        black.push_back(i * m + j);
                        // help to find easier
                        find_black.insert(i * m + j);
                    }
                }
            }
        }

        createGraph();
        maxFlow();

    }
    return 0;

}