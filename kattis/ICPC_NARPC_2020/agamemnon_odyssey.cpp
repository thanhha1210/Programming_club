#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Edge {
    ll to, weight;
};

vector<vector<Edge>> adj;
vector<ll> dist;
vector<bool> visited;

// Function to perform DFS and return the farthest node along with the maximum distance
pair<ll, ll> dfs(ll u) {
    visited[u] = true;
    pair<ll, ll> farthest = {u, 0}; // {node, distance}
    
    for (Edge edge : adj[u]) {
        ll v = edge.to;
        ll w = edge.weight;
        if (!visited[v]) {
            auto [farthestNode, distFromU] = dfs(v);
            distFromU += w;
            if (distFromU > farthest.second) {
                farthest = {farthestNode, distFromU};
            }
        }
    }
    return farthest;
}

int main() {
    ll n, k;
    cin >> n >> k;
    
    adj.assign(n + 1, vector<Edge>());
    
    // Read the edges
    for (ll i = 0; i < n - 1; i++) {
        ll u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }

    // Step 1: Find the farthest node from any starting point (let's start from node 1)
    visited.assign(n + 1, false);
    auto [v1, _] = dfs(1);
    
    // Step 2: Find the farthest node from v1 to determine the diameter of the tree
    visited.assign(n + 1, false);
    auto [v2, maxResources] = dfs(v1);

    // Output the maximum amount of resources
    cout << maxResources << endl;

    return 0;
}
