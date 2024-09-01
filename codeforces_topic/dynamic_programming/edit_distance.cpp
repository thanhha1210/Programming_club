#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const ll INF = 1e9 + 7;
string s1, s2;
ll n, m;
vll x;
vvll dp;

void dp_func() {
    rep(i, 0, n + 1) {
        dp[i][0] = i;
    }
    rep(j, 0, m + 1) {
        dp[0][j] = j;
    }
    rep(i, 1, n + 1) {
        rep(j, 1, m + 1) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
            }
        }
    }
    cout << dp[n][m] << '\n';   
}


int main() {
    cin >> s1 >> s2;
    n = s1.length();
    m = s2.length();
    dp.assign(n + 1, vll(m + 1, 0));
    dp_func();

    return 0;
}