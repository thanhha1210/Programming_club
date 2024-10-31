#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef set<long long> sll;
const ll INF = 1e8 + 7;

ll n, m, q, a, b, c, cnt;
vvll adj;
vb check;
vll tin, low, p;
sll s;

void dfs(ll u, ll p = -1) {    // u is to, s is parent
    tin[u] = low[u] = ++c;  
    check[u] = true;
    ll child = 0;
    for (auto to : adj[u]) {
        if (to == p) {
            continue;
        } 
        if (check[to]) {
            low[u] = min(low[u], tin[to]);
        }
        else {
            dfs(to, u);
            low[u] = min(low[u], low[to]);
            if (low[to] >= tin[u] && p != -1) {
                s.insert(u);  
            }
            child++;
        }
    }
    if (p == -1 && child > 1) {
        s.insert(1);
    }
}


int main() {
    while (cin >> n >> m) {
        adj.clear();
        tin.clear();
        low.clear();
        s.clear();
        if (n == 0 && m == 0)
            break;
        cnt = 0, c = 0;
        adj.assign(n + 1, vll());
        tin.assign(n + 1, -1);
        low.assign(n + 1, -1);
        check.assign(n + 1, false);
        rep(i, 0, m) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }    
        rep (i, 1, n + 1) {
            if (!check[i])
                dfs(i);
        }
        // rep(i, 1, n + 1) {
        //     cout << tin[i] << " " << low[i] << '\n';
        // }
        cout << s.size() << '\n';
    }
}