#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

ll n, m, a, b;
vll check, res;
vvll adj;

void dfs(ll s) {
    check[s] = 1;
    for (auto v : adj[s]) {
        if (check[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, vll());
    check.assign(n + 1, 0);
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    rep(i, 1, n + 1) {
        if (check[i] == 0) {
            dfs(i);
            res.push_back(i);
        }
    }
    cout << res.size() - 1 << "\n";
    rep(i, 1, res.size()) {
        cout << res[0] << " " << res[i] << '\n';
    }

}