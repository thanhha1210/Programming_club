#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<vector<pair<int, int>>> vvpii;
const int INF = 1e9;
/*
    Objective : end is start of dijkstra, reverse all edge 
*/

int n, m, e, t, a, b, c;
vvpii adj;
vi dis;

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, e});

    while (!pq.empty()) {
        int d = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (d != dis[v]) {
            continue;
        }

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;
            if (dis[v] + len < dis[to]) {
                dis[to] = dis[v] + len;
                pq.push({dis[to], to});
            }
        }
    }

    int cnt = 0;
    rep(i, 1, n + 1) {
        if (dis[i] <= t) {
            cnt++;
        }
    }
    cout << cnt << '\n';
   
}

int main() {
    cin >> n >> e >> t >> m;
    adj.resize(n + 1);
    dis.assign(n + 1, INF);
    dis[e] = 0;
    rep(i, 0, m) {
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
    }
    dijkstra();
    return 0;

}