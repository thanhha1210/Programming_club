#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;
typedef vector<vector<long long>> vvll;
typedef vector<char>vc;
typedef vector<vector<char>> vvc;

const long long MOD = 1e9 + 7;
ll n;
vvc grid;
vvll dp;

void solve() {
    rep(i, 0, n) {
        if (grid[i][0] == '.') {
            dp[i][0] = 1;
        }
        else {
            break;
        }
    }
       
     rep(i, 0, n) {
        if (grid[0][i] == '.') {
            dp[0][i] = 1;
        }
        else {
            break;
        }
    }
    
    rep(i, 1, n) {
        rep(j, 1, n) {
            if (grid[i][j] == '.') {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1];
    
}

int main() {
    cin >> n;
    grid.assign(n, vc(n));
    dp.assign(n, vll(n, 0));
    rep(i, 0, n) 
        rep(j, 0, n)
            cin >> grid[i][j];
    solve();
    return 0;
}