#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const ll INF = 1e9 + 7;
ll n, m, ans = 0;
vll x;
vvll dp;

void dp_func() {
    if (x[0] == 0) {
        rep(j, 1, m + 1) {
            dp[0][j] = 1;
        }
    }
    else {
        dp[0][x[0]] = 1;
    }
    rep(i, 1, n) {
        if (x[i] == 0) {
            rep(j, 1, m + 1) {
                dp[i][j] = dp[i - 1][j];
                if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % INF;
                if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % INF;
            }
        }
        else {
            ll j = x[i];
            dp[i][j] = dp[i - 1][j];
            if (j > 1) dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % INF;
            if (j < m) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % INF;
        }
    }

    if (x[n - 1] != 0) {
        ans = dp[n - 1][x[n - 1]];
    }
    else {
        rep(j, 1,  m + 1) {
            ans = (ans + dp[n - 1][j]) % INF;
        }
    }

    cout << ans << '\n';

}


int main() {
    cin >> n >> m;
    x.resize(n);
    dp.assign(n, vll(m + 1, 0));
    rep(i, 0, n) {
        cin >> x[i];
    }
   
    dp_func();
    return 0;
}