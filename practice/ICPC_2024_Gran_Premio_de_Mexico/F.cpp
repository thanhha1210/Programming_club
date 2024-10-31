#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i= j; i < n; i++)
typedef vector<long long> vll;
vll a, b;

bool check(int d) {
    rep(i, 0, 4) {
        if (b[i] == d)
            return true;
    }
    return false;
}

int main() {
    a.resize(5);
    b.resize(4);
    rep(i, 0, 5) cin >> a[i];
    rep(i, 0, 4) cin >> b[i];

    rep(i, 0, 5) {
        if (!check(a[i]))
            cout << a[i];
    }
 
    return 0;
}