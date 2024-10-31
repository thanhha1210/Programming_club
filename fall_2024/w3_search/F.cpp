#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;

ll n, m, k, ans = 1;

bool isValid(ll h) {
    ll sum = h;
    ll left = min(k - 1, h - 1), right = min(n - k, h - 1);
    
    rep(i, 0, left) {
        sum += h - i - 1;
    }
    rep(i, 0, right) {
        sum += h - i - 1;
    }
    return sum <= m;
}

void find() {
    ll l = 1, r = m + 1;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (isValid(mid)) {
            ans = max(ans, mid);  
            l = mid + 1; 
        } 
        else {
            r = mid - 1;
        }
    }
    if (isValid(ans + 1))
        ans++;
    if (!isValid(ans))
        ans--;
    cout << ans + 1;  
}

int main() {
    cin >> n >> m >> k;
    m -= n;  
    find();
    return 0;
}
