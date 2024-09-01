#include<bits/stdc++.h>

using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<double> vdb;

void solve() {

}

int main() {
    ll x, y, n, t;
    
    cin >> t;
    while (t--) {
        cin >> n;
        vdb a(n);
        rep(i, 0, n) {
            cin >> x >> y;
            if (x == 0) {
                a[i] = 0;
            }
            else {
                a[i] = atan(y / x * 1.0) * 180 / M_PI;
            }
        }
        rep(i, 0, n)
            cout << a[i] << " ";
        cout << '\n';
    }
    return 0;
}
