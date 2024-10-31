#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, k, maxx = 0;
vll a, b;

bool checkValid(ll m) {
    ll sum = 0;
    rep(i, 0, n) {
        if (m * a[i] - b[i] > 0)
            sum += m * a[i] - b[i];
        if (sum > k)
            return false;
    }
    return true;
}

ll solve() {
    ll l = 0, r = maxx + k + 9;
    while (l <= r) {
        ll m = (r + l) / 2;
        if (checkValid(m) && !checkValid(m + 1)) {
            return m;
        }
        if (!checkValid(m))  {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

}


int main() {
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n){
        cin >> b[i];
        if(b[i] > maxx)
            maxx = b[i];
    }

    cout << solve();

}