#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll l, h, cnt = 0;
bool check(int& d) {
    vll a(10, 0);
    string t = to_string(d);
    rep(i, 0, t.size()) {
        int k = t[i] - '0';
        a[k] ++;
        if (k == 0 || (a[k] != 1) || (d % k != 0)) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> l >> h;
    rep(i, l, h) {
        if (check(i)) {
            cnt++;
        }
    }
    cout << cnt;
}