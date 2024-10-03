#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;
typedef vector<vector<long long>> vvll;

int N, W;
string s, t1, t2;
vll w, v;
vvll dp;

void solve() {
    rep(i, 1, N + 1) {
        for (int j = W; j >= 0; j--) {
            if (j >= w[i]) {  
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
  
    long long maxx = dp[N][W];  
    cout << maxx << '\n';
}


int main() {
    cin >> N >> W;
    v.resize(N + 1);
    w.resize(N + 1);
    rep(i, 1, N + 1) 
        cin >> w[i] >> v[i];
    dp.assign(N + 1, vll(W + 1, 0));
    solve();
    return 0;
}