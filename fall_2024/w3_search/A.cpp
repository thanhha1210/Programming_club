#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, m, k, l, r, cnt = 0;
vll a, b;

int main() {
    cin >> n >> m >> k;
    a.resize(n);
    b.resize(m);
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, m) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    l = 0, r = 0;
    while (l < n && r < m) {
        if (abs(a[l] - b[r]) <= k) {
            l++;
            r++;
            cnt++;
        }
        else if (a[l] > b[r]) {
            r++;
        }
        else 
            l++;
    }

    cout << cnt;
    return 0;

}
