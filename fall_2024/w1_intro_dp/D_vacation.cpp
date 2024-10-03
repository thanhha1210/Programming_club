#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;
typedef vector<vector<long long>> vvll;

ll n;
vll a, b, c;
vvll dp;

void solve() {
    dp[0][0] = a[0];
    dp[0][1] = b[0];
    dp[0][2] = c[0];
    rep(i, 1, n) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + c[i];
    }

    cout << max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
}

int main() {
    cin >> n;
    dp.assign(n, vll(3, 0));
    a.resize(n);
    b.resize(n);
    c.resize(n);
    rep(i, 0, n) {
        cin >> a[i] >> b[i] >> c[i]; 
    }    
    solve();
    return 0;
}