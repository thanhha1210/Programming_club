#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;

ll n, m, a, b, cnt = 0;
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
    res.push_back(k);
    reverse(res.begin(), res.end());
    cout << res.size() << '\n';
    rep(i, 0, res.size())
        cout << res[i] << " ";
}


void dfs(int s) {
    visited[s] = true;
    for (auto v : adj[s]) {
        if (!visited[v]) {
            p[v] = s;
            dfs(v);
            if (check) return; 
        }
        else if (s != p[v]) {
            res.push_back(v);
            res.push_back(s);
            check = true;
            backtrack();
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
        adj[b].push_back(a);
    }
    rep(i, 0, n) {
        if (!visited[i]) {
            dfs(i);
        }
    }
     if (!check) {
        cout << "IMPOSSIBLE\n";
    }
}