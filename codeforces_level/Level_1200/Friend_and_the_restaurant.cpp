#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

void solve(ll& n, vll& b) {
    int l = 0, r = n - 1, d = 0;

    while (l < r) {
        if (b[l] + b[r] >= 0) {
            d++;
            l++; r--;
        }
        else 
            l++;
    }

    cout << d << endl;
}


int main() {
    ll t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vll a(n), b(n);
        rep(i, 0, n)
            cin >> a[i];
        rep(i, 0, n) {
            cin >> x;
            b[i] = x - a[i];
        }
        sort(b.begin(), b.end());
        solve(n, b);
    }
}