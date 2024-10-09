#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<pair<long long, long long>> vpll;


ll n, u, v;
vll nodes, p;  // nodes - color of each node, p - parent array
vvll adj, layer; 
vector<unordered_map<ll, ll>> a;  // a[u] holds {color, frequency} 
unordered_map<ll, ll> total;      
vpll edges;                       

void bfs() {
    queue<pair<ll, ll>> q;
    q.push({1, 1});  
    p[1] = -2;
    
    while (!q.empty()) {
        int u = q.front().first;
        int d = q.front().second;
        layer[d].push_back(u);
        q.pop();
        
        for (auto v : adj[u]) {
            if (p[v] == -1) {    
                p[v] = u;         
                q.push({v, d + 1});
            }
        }
    }
}

void collectNode() {
    for (int i = layer.size() - 1; i >= 0; i--) {
        rep(j, 0, layer[i].size()) {
            int u = layer[i][j]; 
            a[u][nodes[u]]++;
          
            for (auto v : adj[u]) {
                if (v != p[u]) {  
                    for (auto pair : a[v]) {
                        a[u][pair.first] += pair.second;  
                    }
                }
            }
        }
    }
}

void swap(ll &a, ll &b) {
    ll temp = a;
    a = b;
    b = temp;
}

void checkAns() {
    rep(i, 0, edges.size()) {
        ll cnt = 0;
        int u = edges[i].first;
        int v = edges[i].second;
        
        if (p[v] != u || v == 1) {
            swap(u, v);
        }

        for (auto colorFreq : a[v]) {
            ll color = colorFreq.first;
            ll k2 = colorFreq.second;        
            ll k1 = total[color] - k2;        
            cnt += k1 * k2;                    
        }

        cout << cnt << "\n";  
    }
}

int main() {
    cin >> n;
    
    
    nodes.assign(n + 1, 0);     
    p.assign(n + 1, -1);        
    adj.assign(n + 1, vll());   
    layer.assign(n + 1, vll()); 
    a.resize(n + 1);            
    
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

    bfs();
    collectNode();
    checkAns();

    return 0;
}
