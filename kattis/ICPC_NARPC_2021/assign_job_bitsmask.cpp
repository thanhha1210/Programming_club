#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

ll cost[21][21];
ll dp[21][(1 << 21)];   // 21 * 2^21
ll t, n, m;

ll solve(ll i, ll mask, ll& n) {
    if (i == n) return 0;   // base case, done all
    if (dp[i][mask] != -1) 
        return dp[i][mask];
    ll ans = LLONG_MAX;
    rep(j, 0, n) {
        // check if guy j-th is available
        if ((mask & (1<<j) )!= 0) {
            // if available, assign j to job i
            // mask & (1 << j) will exclude person j
            ans = min(ans, cost[j][i] + solve(i + 1, mask ^ (1 << j), n));
        }
    }
    return dp[i][mask] = ans;
}

int main() {
    cin >> n;
    memset(dp, -1, sizeof dp);
    rep(i, 0, n) rep(j, 0, n) cin >> cost[i][j];
    cout << solve(0, (1 << n) - 1, n);  // 0 -> 2^n - 1 mask, n people 
}

/*
4
9 2 7 8
6 4 3 7
5 8 1 8
7 6 9 4

*/
