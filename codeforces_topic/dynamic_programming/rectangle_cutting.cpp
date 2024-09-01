#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const ll INF = 1e12 + 7;
ll n, m, ans = 0;
vll x;
vvll dp;

// if i == j -> 0
// else -> can cut vertically/ horizontally (find position k to cut)

void dp_func() {
    rep(i, 1, n + 1)
        dp[i][0] = 0;
    rep(j, 1, m + 1)
        dp[0][j] = 0;
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            if (i == j) {
                dp[i][j] = 0;
            }
            else {
                // cut horizontally
                rep(k, 1, i) {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                // cut vertically
                rep(k, 1, j) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    cout << dp[n][m] << '\n';
}


int main() {
    cin >> n >> m;
    dp.assign(n + 1, vll(m + 1,INF));
    dp_func();
    
    return 0;
}