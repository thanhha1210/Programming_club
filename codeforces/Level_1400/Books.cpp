#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

void solve(ll n, ll t, vll& a) {
    int l = n, r = n, res = 0;
    ll s = 0;
    rep(i, 0, n) {
        if (a[i] <= t) {
            l = i;
            r = i + 1;
            res = 1;
            s = a[i];
            break;
        }
    }
    while (r < n) {
        if (s + a[r] <= t) {
            s = s + a[r];
            r++;
        } 
        else {
            s -= a[l];
            l++;
        }
        res = max(res, r - l);
    }   
    cout << res << endl;
}

int main() {
    ll n, t;
    cin >> n >> t;
    vll a(n);
    rep(i, 0, n)
        cin >> a[i];
    solve(n, t, a);
}