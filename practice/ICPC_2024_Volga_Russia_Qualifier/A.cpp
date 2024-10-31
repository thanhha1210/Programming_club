#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

ll n, d = 1e9;

int main() {
    cin >> n;
    rep(i, 1, sqrt(n) + 1) {
        if (n % i == 0) {
            d = min(d, (i - 1) + (n / i - 1));
        }
    }
    cout << d;
}