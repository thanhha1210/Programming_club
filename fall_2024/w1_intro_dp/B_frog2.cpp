#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;

ll n, k;
vll h, dp;

int main() {
    cin >> n >> k;
    h.resize(n);
    dp.assign(n, 0);
    rep(i, 0, n) 
        cin >> h[i];
    dp[0] = 0;
    dp[1] = abs(h[1] - h[0]);
    rep(i, 2, n) {
        dp[i] = dp[i - 1] + abs(h[i] - h[i - 1]);
        for (int j = 2; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
            }
            else {
                break;
            }
        }
            
    }
    cout << dp[n - 1];
    return 0;
}