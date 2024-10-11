#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

int n, x1, x2;

int main() {
    cin >> n;
    cout << n << ": \n";
    rep(i, 1, n / 2 + 1) {
        x1 = i;
        x2 = i + 1;
        if ((n % (2 * x1) == 0  || (n - x1) % (2 * x1) == 0)  && (x1 != 1)) {
            cout << x1 << "," << x1 << '\n';
        }
        if ((n % (x1 + x2) == 0) || ((n - x2) % (x1 + x2) == 0)) {
            cout << x2 << "," << x1 << '\n';
        }
    }
}