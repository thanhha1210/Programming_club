#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, k, minx = 1e9, maxx = 0, cost = 1e18;
vll a, b;
string s;

ll f(ll m) {
    ll sum = 0;
    rep(i, 0, n) {
        sum += abs(m - a[i]);
    }
    return sum;
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
        if (a[i] < minx) minx = a[i];
        if (a[i] > maxx) maxx = a[i];
    } 
    ll l = minx, r = maxx;
   
    while (r - l > 6) {
        ll m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (f(m1) == f(m2)) {
            l = m1, r = m2;
        }
        else if (f(m1) < f(m2)) {
            r = m2;
            cost = min(cost, f(m1));
        }
        else{
            l = m1;
            cost = min(cost, f(m2));
        }
    }
    rep(j, l, r + 1) {
        cost = min(cost, f(j));
    }

    cout << cost;
}




   while (r - l > 6) {
        ll m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
        if (f(m1) == f(m2)) {
            l = m1, r = m2;
        }
        else if (f(m1) < f(m2)) r = m2;
        else l = m1;
    }
    rep(j, l, r + 1) {
        // find 
    }
  