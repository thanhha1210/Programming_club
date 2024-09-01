#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rep_rev(i, n, j) for (int i = n; i > j; i--)
typedef vector<long long> vll;
typedef long long ll;

void solve(ll& n, ll& minx, ll& maxx, vll& a) {
    int l, r, d = 0;
    rep_rev(i, n - 1, 0) {
        if (a[0] + a[i] <= maxx) {
            r = i;
            l = i - 1;
            break;
        }
    }
    rep(k, 0, n) {
        rep
        
    }

}

int main() {
    ll t, n, l, r;
    cin >> t;
    while (t--) {
        cin >> n >> l >> r;
        vll a(n);
        rep(i, 0, n) 
            cin >> a[i];
        sort(a.begin(), a.end());
        solve(n, l, r, a);
    }
}