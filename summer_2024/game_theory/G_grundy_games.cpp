#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

vector<int>dp(1e6 + 7, -1);

int g(ll n) {
    if (dp[n] != -1)
        return dp[n];
    int mex = {};

}

void solve(ll n) {

}


int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        solve(n);
    }
}