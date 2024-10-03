#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
const long long MAXN = 1e9 + 7;
int n, m;
vvi adj, out;    
vi indegree, res, ans, dp;   

// topological sort
void topoSort() {
    queue<int> q;
    rep(i, 1, n + 1) {
        if (indegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        res.push_back(v);

        for (auto u : adj[v]) {
            indegree[u]--;             
            if (indegree[u] == 0) {     // mean learn all the required course before this
                q.push(u);
            }
        }
    }
    
}

void trackBack() {
    dp[1] = 1;
    rep(i, 1, res.size()) {
        int v = res[i];
        for (auto u : out[v]) {
            dp[v] = (dp[v] + dp[u]) % MAXN;
        }
    }
    cout << dp[n] << '\n';    
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);  
    out.resize(n + 1);     
    indegree.assign(n + 1, 0); 
    dp.assign(n + 1, 0);
  
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        out[b].push_back(a);    // out[b] hold node go to b
        indegree[b]++;       
    }
    topoSort();
    trackBack();

    return 0;
}
