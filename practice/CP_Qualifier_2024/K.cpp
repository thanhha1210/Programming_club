#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

ll n, m;
vll p, a;   // p - press, a - actual
vvll dp;
int point (int x, int y) {
    if (abs(x - y) <= 15) return 7;
    if (abs(x - y) <= 23) return 6;
    if (abs(x - y) <= 43) return 4;
    if (abs(x - y) <= 102) return 2;
    return 0;
}
void solve() {
    rep(i, 0, n + 1)
        dp[i][0] = 0;
    rep(i, 0, m + 1)
        dp[0][i] = 0;
    
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  
            
            int score = point(p[i], a[j]);
            if (score > 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][ j- 1] + score);  
            }
        }
    }
    cout << dp[n][m];
}
int main() {
    cin >> n >> m;
    p.resize(n + 1);
    a.resize(m + 1);
    dp.resize(n + 1, vll(m + 1, 0));

    rep(i, 1, n + 1) {
        cin >> p[i];
    }
    rep(i, 1, m + 1) {
        cin >> a[i];
    }
    solve();
}