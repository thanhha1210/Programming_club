#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<bool> vb;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

ll n, m, a, b;
vb check;
vvll adj;


void dfs(int s) {
    check[s] = true;
    for (auto v : adj[s]) {
        if (!check[v]) {
            dfs(v);
        }
    }
}

void printOutput() {
    int d = 0;
    rep (i, 1, n + 1) {
        if (check[i] == false) {
            cout << i << "\n";
            d++;
        }
    }
    if (d == 0) {
        cout << "Connected\n";
    }
    return; 
}

int main() {
    cin >> n >> m;

    adj.assign(n + 1, vll(0));
    check.assign(n + 1, false);

    
    rep(i, 0, m) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1);
    printOutput();


}