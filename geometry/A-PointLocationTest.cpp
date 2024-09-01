#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

void solve(ll x1, ll x2, ll x3, ll y1, ll y2, ll y3) {
    ll X1 = x3 - x1;
    ll Y1 = y3 - y1;
    ll X2 = x3 - x2;
    ll Y2 = y3 - y2;
    ll k = X1 * Y2 - X2 * Y1;
    if (k > 0) 
        cout << "LEFT\n";
    else if (k < 0)
        cout << "RIGHT\n";
    else
        cout << "TOUCH\n";

}

int main() {
    ll t, x1, x2, x3, y1, y2, y3;
    cin >> t;
    while (t--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        solve(x1, x2, x3, y1, y2, y3);
    }

}