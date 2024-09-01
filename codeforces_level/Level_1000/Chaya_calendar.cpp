#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef vector<long long> vll;
typedef long long ll;

ll solve(const ll& n, const vll& a) {
    ll time = a[0];
    for (int i = 1; i < n; i++) {
        if (time < a[i])
            time = a[i];
        else {
            ll k = ceil(time / a[i] * 1.0);
            ll temp = k * a[i];
            if (temp <= time)
                temp += a[i];
            time = temp;
        }
    }
    return time;
}

int main() {
    ll t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vll a(n);
        rep(i, 0, n)
            cin >> a[i];
        cout << solve(n, a) << endl;
    }
}
