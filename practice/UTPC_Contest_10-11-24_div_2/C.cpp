#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rrep(i, n, j) for (int i = n; i > j; i--)
typedef long long ll;

ll n, k, x, y;

int main() {
    cin >> n >> k;
    int x = n - k, d = n;
    while (x > 0) {
        cout << d << " ";
        d--;
        x--;
    } 
    rep(i, 1, k + 1)
        cout << i << " ";  
}