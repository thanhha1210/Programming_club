#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;

int main() {
    int t, n, x, y, c1, c2;
    double d;
    cin >> t;
    while (t--) {
        cin >> n;
        c1 = 0, c2 = 0;
        d = 0;
        vi a(n), b(n);
        rep(i, 0, 2 * n) {
            cin >> x >> y;
            if (x == 0)
                b[c2++] = abs(y);
            else
                a[c1++] = abs(x);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        rep(i, 0, n) {
            d += sqrt(a[i] * 1.0 * a[i] + b[i] * 1.0 * b[i]);
        }
        cout  << setprecision(14) << d << '\n';

    }
}