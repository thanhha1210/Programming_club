#include <bits/stdc++.h>
using namespace std;
queue<int> q;
void BFS(int s, vector<bool>& visit, const vector<vector<int>>& adj) {
    
    if (!visit[s]) {
        visit[s] = true;
        q.push(s);
        while (!q.empty()) {
            int k = q.front();
            q.pop();
            cout << k << " ";
            for (auto v : adj[k]) {
                if (!visit[v]) {
                    visit[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    int n, a, b, m; // n = # of nodes, m = # of edges
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visit(n + 1, false);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    BFS(1, visit, adj);
    for (int i = 1; i <=n ; i++)
        if (visit[i] == false)
            cout << i << " ";
    return 0;
}

/*
5 5
1 2
1 3
1 4
2 3
2 4
*/
