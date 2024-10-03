#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int n, m;
vvi adj;    
vi indegree, res;   

// topological sort
bool toposort() {
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

int main() {
    cin >> n >> m;
    adj.resize(n + 1);       
    indegree.assign(n + 1, 0); 
   
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b); 
        indegree[b]++;       
    }

    if (toposort()) {
        rep(i, 0, res.size()) {
            cout << res[i] << " ";
        }
    }   
    else {
        cout << "IMPOSSIBLE\n";
    }
    

    return 0;
}
