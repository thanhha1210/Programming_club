#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
 
ll n, m, a, b;
vvll adj;
vll p, res;
vb visited;
bool check = false;
 
void backtrack() {
    ll k = res[0];
    ll x = p[res[1]];
    while (x != k) {
        res.push_back(x);
        x = p[x];
    }
    res.push_back(k); // Complete the cycle by including the start node
    reverse(res.begin(), res.end()); // Reverse to display the cycle in the correct order
    cout << res.size() << '\n';
    for (ll r : res)
        cout << r << " ";
    cout << '\n';
}
 
void dfs(int s) {
    visited[s] = true;
    for (auto v : adj[s]) {
        if (!visited[v]) {
            p[v] = s;
            dfs(v);
            if (check) return; // Terminate DFS if a cycle is found
        }
        else if (v != p[s]) { // Found a back edge (cycle)
            res.push_back(v); // Start of the cycle
            res.push_back(s); // End of the cycle
            check = true;
            backtrack(); // Trace back to find the entire cycle
            return;
        }
    }
}
 
int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll());
    visited.assign(n + 1, false);
    p.assign(n + 1, -1);
    
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
 
    rep(i, 1, n + 1) {
        if (!visited[i] && !check) {
            dfs(i);
        }
    }
 
    if (!check) {
        cout << "IMPOSSIBLE\n";
    }
    
    return 0;
}