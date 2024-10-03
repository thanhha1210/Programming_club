#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int n, m;
vvi adj, out;    
vi indegree, res, ans, dp, p;   

// topological sort
bool topoSort() {
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
    return res.size() == n;
}

void trackBack() {
    int index = 0;
    rep(i, 0, res.size()) {
        if (res[i] == 1) {
            index = i;
            break;
        }
    }
    dp[1] = 1;
    rep(i, index + 1, res.size()) {
        int v = res[i];
        for (auto u : out[v]) {
            if (dp[u] > 0 && dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
                p[v] = u;
            }
        }
    }
    if (dp[n] == 0) {
        cout << "IMPOSSIBLE";
    }
    else {
        cout << dp[n] << '\n';
    
        int k = n;
        while (k != 1) {
            ans.push_back(k);
            k = p[k];
        }
        ans.push_back(k);
        reverse(ans.begin(), ans.end());
        rep(i, 0, ans.size()) {
            cout << ans[i] << ' ';
        }
    }
    
    

    
}

int main() {
    cin >> n >> m;
    adj.resize(n + 1);  
    out.resize(n + 1);     
    indegree.assign(n + 1, 0); 
    dp.assign(n + 1, 0);
    p.assign(n + 1, -1);
   
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        out[b].push_back(a);    // out[b] hold node go to b
        indegree[b]++;       
    }

    if (!topoSort()) {
        cout << "IMPOSSIBLE\n";
    }   
    else {
       trackBack();
    }
    

    return 0;
}
