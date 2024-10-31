#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef map<long long, long long> mll;

ll n, sum = 0, sumLeft = 0;
vll a;
mll s;

void solve() {
    if (sum % 2 != 0) {
        cout << "NO\n";
        return;
    }
    sum /= 2;
    rep(i, n / 2, n) {
        ll k = sumLeft + a[i] - sum ;
        if (s.find(k) != s.end()) {
            cout << "YES\n";
            cout << s[k] + 1 << " " << i + 1;
            return;
        }  
    }
    cout << "NO\n";
    return;
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
        sum += a[i];
        if (i < n / 2) {
            sumLeft += a[i];
        }
        s.insert({a[i], i});
    }
    solve();
    return 0;
}