#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;

ll n;
vll h, dp;

int main() {
    cin >> n;
    h.resize(n);
    dp.assign(n, 0);
    rep(i, 0, n) 
        cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    rep(i, 2, n) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[n - 1];
    return 0;
}