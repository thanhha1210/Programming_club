#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<pair<long long, long long>> vpll;

ll n, u, v;
vll nodes, subSize;                         // nodes - color of each node
vvll adj;
unordered_map<ll, ll> total;  
vector<unordered_map<ll, ll>> subColor;   
vpll edges;  
vector<ll> answers;


void dfs(ll u, ll p) {
    subSize[u] = 1;
    subColor[u][nodes[u]]++;
    
    for (ll v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            subSize[u] += subSize[v];

            if (subColor[v].size() > subColor[u].size()) {
                swap(subColor[u], subColor[v]); 
            }
            for (auto &[color, freq] : subColor[v]) {
                subColor[u][color] += freq;
            }
        }
    }
}

void checkAns() {
    for (auto &[u, v] : edges) {
        if (v == 1 || subSize[v] > subSize[u]) {
            swap(u, v); 
        } 

        ll cnt = 0;
        for (auto &[color, cntInV] : subColor[v]) {
            ll totalCnt = total[color];
            ll cntInU = totalCnt - cntInV;       
            cnt += cntInU * cntInV;             
        }
        cout << cnt << "\n";                    
    }
}
int main() {
    cin >> n;

    nodes.assign(n + 1, 0);
    adj.assign(n + 1, vll());
    subSize.assign(n + 1, 0);
    subColor.resize(n + 1);
    
    rep(i, 1, n + 1) {
        cin >> nodes[i];
        total[nodes[i]]++;  
    }
    
    rep(i, 1, n) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }

    dfs(1, -1);          
    checkAns();           

    return 0;
}