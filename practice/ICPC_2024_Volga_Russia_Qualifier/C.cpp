#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

ll a, b, c, d1, d2, d3, s = 0;


int main() {
    cin >> a >> b >> c;
    s = a + b + c;
    d1 = min(a, (min(b, c)));
    d3 = max(a, max(b, c));
    d2 = s - d1 -d3;

    if (s % 2 == 1) {
        cout << -1;
        return 0;
    }

    if (d1 + d2 >= d3) {
        cout << d1;
    }
    else {
        cout << d1 + ((d3 - d1 - d2) / 2);
    }
    return 0;

}