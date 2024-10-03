#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

vll sum, q, a;
ll n, m, k;

void findX(ll k) {
    if (sum[n - 1] < k) {
        cout << -1 << '\n';
        return;
    } 

    int l = 0, r = n - 1, mid = (l + r) / 2;
    while (l <= r) {
        mid = (l + r) / 2;
        if (sum[mid] == k) {
            cout << mid + 1 << '\n';
            return;
        }
        else if (sum[mid] < k) {
            l = mid + 1;
        }
        else if (sum[mid] > k) {
            r = mid - 1;
        }
    }
    if (sum[l - 1] >= k) {
        cout << l << '\n';
    }
    else 
        cout << l + 1 << '\n';

}

int main() {
    cin >> n >> m;
    a.resize(n);
    sum.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
        if (i == 0)
            sum[i] = a[i];
        else
            sum[i] = sum[i - 1] + a[i];
    }
    rep(i, 0, m) {
        cin >> k;
        findX(k);
    }
    return 0;
}