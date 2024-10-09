#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;


const long long INF = 1e13 + 9;
ll n, m, t, a, b, c, cnt = 0;
vvll dp;


void floyd_warshall() {
    rep(k, 1, n + 1) {
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                if (dp[i][k] != INF && dp[k][j] != INF && dp[i][k] + dp[k][j] < dp[i][j])
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }
}

int main() {
    cin >> n >> m >> t;
    dp.assign(n + 1, vll(n + 1, INF));
    rep(i, 1, n + 1)
        dp[i][i] = 0;
    rep(i, 0, m) {
        cin >> a >> b >> c;
        dp[a][b] = min(dp[a][b], c);
        dp[b][a] = min(dp[a][b], c);
    }
    
    floyd_warshall();
    rep(i, 0, t) {
        cin >> a >> b;
        if (dp[a][b] == INF) {
            cout << -1 << '\n';        
        }
        else {
            cout << dp[a][b] << '\n';
        }
    }
    return 0;
}