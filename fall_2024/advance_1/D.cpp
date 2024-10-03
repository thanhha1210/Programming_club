#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
int n, m, x, y, sum = 0;


int main() {
    rep(i, 0, 5) {
        cin >> x >> y;
        sum += x * y;
    }
    sum /= 5;
    cin >> n >> m;
    cout << int(sum * n / m);
    return 0;
}