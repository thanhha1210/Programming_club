#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
ll n;
vll a, minx, maxx, res;

int main() {
    cin >> n;
    a.resize(n);
    minx.resize(n);
    maxx.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
        if (i == 0) {
            maxx[i] = a[i];
        }
        else {
            maxx[i] = max(a[i], maxx[i - 1]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            minx[i] = a[i];
        }
        else {
            minx[i] = min(a[i], minx[i + 1]);
        }
    }
    rep(i, 0, n) {
        if (i == 0) {
            if (a[i] <= minx[i]) {
                res.push_back(a[i]);
            }
        }
        else if (i == n - 1) {
            if (a[i] >= maxx[i]) {
                res.push_back(a[i]);
            }
        }
        else {
            if (a[i] >= maxx[i] && a[i] <= minx[i]) {
                res.push_back(a[i]);
            }
        }
    }
    
    cout << res.size() << " ";
    int i = 0;
    while (i < res.size() && i < 100) {
        cout << res[i] << " ";
        i++;
    }
    return 0;
}