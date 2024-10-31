#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, q, k, l, r, cnt = 0;
vll a, b;

ll find(const ll& x) {
    ll l = 0, r = n - 1;  
    while (l <= r) {
        ll m = (l + r) / 2;
        if (a[m] <= x) {
            l = m + 1;  
        } 
        else {
            r = m - 1;  
        }
    }
    return l; 
}


int main() {
    cin >> n;
    a.resize(n, 0);
    rep(i, 0, n) cin >> a[i];
    sort(a.begin(), a.end());

    cin >> q;
    rep(i, 0, q) {
        cin >> k;
        cout << find(k) << '\n';
    } 
    return 0;
}
