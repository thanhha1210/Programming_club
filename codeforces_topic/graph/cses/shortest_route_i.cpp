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

const ll INF = 1e15 + 7;
ll n, m, a, b, w, cnt = 0;
vvpll adj;
vll p, res, dis;


void dijisktra(ll s) {
    
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push({0, s});
    dis[s] = 0;

    while (!pq.empty()) {
        ll d = pq.top().first;
        ll v = pq.top().second;
        pq.pop();
        
        if (d != dis[v]) {
            continue;
        }
        for (auto to : adj[v]) {
            if (dis[to.first] > d + to.second) {
                dis[to.first] = d + to.second;
                pq.push({dis[to.first], to.first});
            }
        }
    }
    rep(i, 1, n + 1) {
        cout << dis[i] << " ";
    }
}



int main() {
    cin >> n >> m;
    dis.assign(n + 1, INF);
    adj.assign(n + 1, vpll());
    rep(i, 0, m) {
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
    }
    dijisktra(1);

}