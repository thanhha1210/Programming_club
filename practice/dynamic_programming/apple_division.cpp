#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

void solve(const vll& a, const ll& sum, const ll& n) {
    ll minx = LLONG_MAX;
    rep(i, 0, (1 << n)) {   // 2 to power of n
        ll x = 0;
        rep(j, 0, n) {
            if (i & (1 << j)) {  
                x += a[j];
            }
        }
        if (abs(x - (sum - x)) < minx) {
            minx = abs(x - (sum - x));
        }
    }
    cout << minx << endl;
}

int main() {
    ll n, sum = 0;
    cin >> n;
    vll a(n);
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
    }
    solve(a, sum, n);
    return 0;
}
