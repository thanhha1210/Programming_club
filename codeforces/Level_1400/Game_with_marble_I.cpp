#include <bits/stdc++.h>    
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<long long> vll;
typedef pair<long long, int> plli;
typedef vector<pair<long long, int>> vplli;
typedef vector<int> vi;
ll  MAX_N = 1e9 + 7;

void solve(vll& a, vll& b, vplli& c, ll& n) {
    ll res = 0;
    rep(i, 0, n) {
        int j = c[i].second;
        if (i % 2 == 0) {
            res += (a[j] - 1);
        }
        else {
            res -= (b[j] - 1);
        }
    }

    cout << res << endl;
    
}

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vll a(n, 0), b(n, 0);
        vplli c(n);
        
        rep(i, 0, n) {
           cin >> a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
            c[i].first = a[i] - 1 + b[i];
            c[i].second = i;
        }
        
        sort(c.begin(), c.end());
        reverse(c.begin(), c.end());
        solve(a, b, c, n);
    }
}