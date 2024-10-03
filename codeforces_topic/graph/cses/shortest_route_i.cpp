#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<pair<long long, long long>>> vvpll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;

ll n, m, a, b, w, cnt = 0;
vvpll adj;
vll p, res;

int dijisktra(ll s) {
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        
    }
}



int main() {
    cin >> n >> m;
    rep(i, 0, m) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});

    }
}