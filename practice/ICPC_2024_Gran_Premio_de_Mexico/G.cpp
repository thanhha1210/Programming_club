#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, x, y, e = 0, o = 0;
vll a, b;

void mod_array() {
    ll k = __gcd(a[0], a[1]);
    rep(i, 2, n) {
        k = __gcd(k, a[i]);
    }
    rep(i, 0, n) {
        a[i] /= k;
    }
}

void solve() {
    mod_array();
    b.assign(10000009, 0);
    rep(i, 0, n) {
        int d = 2;
        while (a[i] != 1) {
            if (a[i] % d == 0) {
                b[d]++;
                if (b[d] > 1) {
                    cout << "NO\n";
                    return;
                }
            }
            while (a[i] % d == 0) {
                a[i] /= d;
            }
            d++;
        }
    }
    cout << "YES\n";
    return;
}


int main() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    solve();
}