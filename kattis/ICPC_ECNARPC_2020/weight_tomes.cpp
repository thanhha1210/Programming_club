#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const ll MAXN = 1e9;
ll n, m, minx = MAXN;
vvll dp;

void createDP() {
    // dp[i][j] -> i = # pallet, j = height
    rep(i, 0, n + 1) {  
        dp[1][i] = i;
    }
    rep(i, 2, m + 1) {  // start with 2 pallet
        rep(j, 1, n + 1) {
            ll minVal = n + 1;
            rep(k, 1, j + 1) {
                ll v1 = dp[i - 1][k - 1];   // collapse
                ll v2 = dp[i][j - k];       // not collapse
                if (v1 < v2) swap(v1, v2);
                if (v1 + 1 < minx) minx = v1 + 1;
            }
            dp[i][j] = minx;
        }
    }

    int start = -1, stop = MAXHEIGHT+1;
    for(int x=1; x<=h; x++) {
        int v1 = table[nP-1][x-1];       // pallet collapses
        int v2 = table[nP][h-x];         // pallet doesn't collapse
        if (v2 > v1)
            v1 = v2;
        if (v1 + 1 == table[nP][h]) {
            stop = x;
            if (start == -1)
                start = x;
        }
    }
}

int main() {
    cin >> n >> m;  // n = # box, m = # pallet
    dp.assign(m + 1, vll(n + 1, MAXN));
    createDP();
    rep(i, 0, m + 1) {
        rep(j, 0, n + 1) 
            cout << dp[i][j] << " ";
        cout << '\n';
    }
    cout << dp[m][n];
}