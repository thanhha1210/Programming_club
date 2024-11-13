#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;

string s;
const ll MAXN = 1e6;
ll a;

void solve() {
    ll sum = 1;
    rep(i, 1, 13) {
        sum *= i;
        if (to_string(sum) == s) {
            cout << i << " ";
            return;
        }
    }
    double sumLog = 0.0;
    rep(i, 1, MAXN) {
        sumLog += log10(i);
        if (floor(sumLog) + 1 == s.length()) {
            cout << i << " ";
            return;
        }
    }
}

int main() {
    cin >> s;
    solve();
}