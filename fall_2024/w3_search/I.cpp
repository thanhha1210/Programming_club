#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, k, m, mina = 1e9 + 10, minb = 1e9 + 10, maxa = 0, maxb = 0, cost = 1e18;
vll a, b;

ll f(ll k) {    // m is max of b, all a have to > m
    ll sum = 0;
    rep(i, 0, n) {
        if (a[i] < k) 
            sum += k - a[i];
    }
    rep(i, 0, m) {
        if (b[i] >= k) 
            sum += b[i] - k;
    }
    return sum;
}

int main() {
    cin >> n >> m;
    a.resize(n);
    b.resize(m);

    rep(i, 0, n) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
    }
    rep(i, 0, m) {
        cin >> b[i];
        maxb = max(maxb, b[i]);
        minb = min(minb, b[i]);
    }

    ll l = min(mina, minb), r = max(maxa, maxb);
    while (r - l > 6) {
        ll m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (f(m1) == f(m2)) {
            l = m1, r = m2;
        }
        else if (f(m1) < f(m2)) {
            r = m2;
            cost = min(cost, f(m1));
        }
        else {
            l = m1;
            cost = min(cost, f(m2));
        }
    }
    rep(j, l, r + 1) {
        cost = min(cost, f(j));
    }

    cout << cost;
}