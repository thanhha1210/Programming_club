#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

void solve(ll& n, vll& a) {
    ll l = 0, r = 0, res = 0;
    while (l < n) {
        if (r < n  && r - l + 1 <= a[r])
            r++;
        else {
            res = res + r - l;
            l++;
        }
    }
    cout << res << "\n";
}

int main (){
    ll t, n;
    cin >> t ;
    while (t--) {
        cin >> n;
        vll a(n);
        rep(i, 0, n) {
            cin >> a[i];
        }
        solve(n, a);
    }

}