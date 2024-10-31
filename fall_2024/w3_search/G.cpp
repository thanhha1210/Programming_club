#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, k, maxx = 1e9, dis = 1e9;
vll a, b;
string s;

ll f(ll s, ll e, ll m) {
    return max(abs(m - s), abs(m - e));
}

int main() {
    cin >> n >> k;
    cin >> s;
    rep(i, 0, s.size()) {
        if (s[i] == '0') {
            a.push_back(i);
        }
    }
    int i = 0;
    while (i + k < a.size()) {
        ll s = a[i], e = a[i + k];
        ll l = i, r = i + k;
        while (r - l > 5) {
            ll m1 = (2 * l + r) / 3, m2 = (l + 2 * r) / 3;
            if (f(s, e, a[m1]) == f(s, e, a[m2])) {
                l = m1, r = m2;
            }
            else if (f(s, e, a[m1]) < f(s, e, a[m2]))
                r = m2;
            else
                l = m1;
            dis = min(dis, f(s, e, a[m1]));
            dis = min(dis, f(s, e, a[m2]));
        }
        rep(j, l, r + 1) {
            dis = min(dis, f(s, e, a[j]));
        }
        i++;
    }
    cout << dis;
}
