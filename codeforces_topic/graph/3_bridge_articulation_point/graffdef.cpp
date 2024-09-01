#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<long long, long long>> vpll;

const long long INF = 1e9;
ll n, m, a, b, cnt = 0;
vvll adj;
vll tin, low;
vb visited;
vpll bridges;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = cnt++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v]) {
                bridges.push_back({v, to});
            }
        }
    }
}

void find_component_size(int v, ll &size) {
    visited[v] = true;
    size++;
    for (int to : adj[v]) {
        if (!visited[to]) {
            find_component_size(to, size);
        }
    }
}

int main() {
    cin >> n >> m;
    tin.assign(n + 1, INF);
    low.assign(n + 1, INF);
    visited.assign(n + 1, false);
    adj.resize(n + 1);
    
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Finding bridges
    dfs(1, -1);

    // Remove all bridges from the graph
    for (auto &e : bridges) {
        adj[e.first].erase(find(adj[e.first].begin(), adj[e.first].end(), e.second));
        adj[e.second].erase(find(adj[e.second].begin(), adj[e.second].end(), e.first));
    }

    // Calculate the size of each connected component
    visited.assign(n + 1, false);
    vector<ll> component_sizes;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            ll size = 0;
            find_component_size(i, size);
            component_sizes.push_back(size);
        }
    }

    // Calculate the number of unique separable pairs
    ll separable_pairs = 0;
    for (ll size : component_sizes) {
        separable_pairs += size * (n - size);
    }
    separable_pairs /= 2;  // Each pair is counted twice

    ll total_pairs = n * (n - 1) / 2;
    double probability = (double)separable_pairs / total_pairs;

    cout << fixed << setprecision(5) << probability << endl;

    return 0;
}
