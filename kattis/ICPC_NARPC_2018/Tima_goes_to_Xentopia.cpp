#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vvll> vvvll;
typedef tuple<ll, ll, ll> tu; // (time, color)
typedef vector<tu> vtu;
typedef vector<vtu> vvtu;
const ll INF = 1e18;

struct State {
    ll u, red, blue;
    ll dis;
    bool operator<(const State &o) const {
        return dis < o.dis;
    }
    bool operator>(const State &o) const {
        return dis > o.dis;
    }
};

// Adjacency list for the graph
vvtu adj;
ll n, m, k1, k2, S, T;
vvvll d;

// Dijkstra's algorithm function
ll dijkstra() {
    // Initializing distance array
    d.assign(n + 1, vvll(k1 + 1, vll(k2 + 1, INF)));
    d[S][0][0] = 0;

    // Min-heap priority queue
    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({S, 0, 0, 0});

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        ll u = curr.u, red = curr.red, blue = curr.blue, dist = curr.dis;

        // If we reached the target node with exact k1 red and k2 blue edges
        if (u == T && red == k1 && blue == k2) {
            return dist;
        }

        // Skip if we already found a shorter path
        if (dist > d[u][red][blue]) {
            continue;
        }

        // Explore neighbors
        for (auto &[v, t, c] : adj[u]) {
            if (c == 1 && red < k1 && d[v][red + 1][blue] > dist + t) {
                d[v][red + 1][blue] = dist + t;
                pq.push({v, red + 1, blue, dist + t});
            }
            if (c == 2 && blue < k2 && d[v][red][blue + 1] > dist + t) {
                d[v][red][blue + 1] = dist + t;
                pq.push({v, red, blue + 1, dist + t});
            }
            if (c == 0 && d[v][red][blue] > dist + t) { // Color 0 (unrestricted edges)
                d[v][red][blue] = dist + t;
                pq.push({v, red, blue, dist + t});
            }
        }
    }
    return -1; // No valid path found
}

int main() {
    cin >> n >> m >> k1 >> k2;
    adj.assign(n + 1, vtu());

    ll u, v, t, color;
    rep(i, 0, m) {
        cin >> u >> v >> t >> color;
        adj[u].emplace_back(v, t, color);
        adj[v].emplace_back(u, t, color); // Bidirectional
    }
    cin >> S >> T;

    cout << dijkstra() << endl;
    return 0;
}
