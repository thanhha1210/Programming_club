#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<long long, long long>> vpll;
typedef vector<vector<long long>> vvll;

ll t, n, r, m, a, b;
vpll s;
vll res;
vvll adj;
bool ans;



bool bfs(long long s, long long d) {
    set<long long> vertex;
    queue<pair<long long, long long>> q;
    q.push({s, 0});
    vertex.insert(s);

    while (!q.empty()) {
        int v = q.front().first;
        int dis = q.front().second;
        q.pop();

        if (dis < d) {
            for (auto to : adj[v]) {
                if (vertex.find(to) == vertex.end()) {
                    vertex.insert(to);
                    q.push({to, dis + 1});
                }
            }
        }
    }

    for (auto i : vertex) {
        res[i]++;
        if (res[i] > 1) {
            return false;
        }
    }

    return true;

}

int main() {
    cin >> t;
    while (t--) {  
        ans = true; 
        cin >> n >> r >> m;
        res.clear();
        adj.clear();
        s.clear();

        res.assign(n + 1, 0);
        adj.resize(n + 1);
        
        rep(i, 0, r) {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        rep(i, 0, m) {
            cin >> a >> b;
            s.push_back({a, b});
        }
        rep(i, 0, m) {
            bool c = bfs(s[i].first, s[i].second);
            if (!c) {
                ans = false;
                break;
            }
        }

        if (!ans) {
            cout << "No" << endl;
        }
        else {
            rep(i, 1, n + 1) {
                if (res[i] != 1) {
                    ans = false;
                    break;
                }
            }
            cout << (ans ? "Yes" :  "No") << endl;
        }
    }
    return 0;
}