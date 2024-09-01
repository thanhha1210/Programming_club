#include <bits/stdc++.h>    
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;
ll  MAX_N = 1e9 + 7;


void solve(vll& a, vll& b, ll& n) {

    ll res = 0;

    rep(k, 0, n) {
        ll minx = MAX_N;
        rep(i, 0, n) {
            int j = i + k;
            if (j >= n) 
                j -= n;
            minx = min(minx, abs(a[i] - b[j]));
        }
        res = max(res, minx);
    }

    cout << res << endl;
    
}

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vll a(n, 0), b(n, 0);
        rep(i, 0, n) {
           cin >> a[i];
        }
        rep(i, 0, n) {
            cin >> b[i];
        }
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        solve(a, b, n);
    }
}