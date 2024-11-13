#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
ll n;
vll v;
void solve() {
    ll l1, l2, lt, a1, a2, at;
    cin >> l1 >> a1 >> l2 >> a2 >> lt >> at;

    vector<pair<ll, ll>> solutions;
    
    for (ll x = 1; l1 * x < lt; ++x) {  
        if ((lt - l1 * x) % l2 == 0) {
            ll y = (lt - l1 * x) / l2;
            if (a1 * x + a2 * y == at) {
                solutions.push_back({x, y});
            }
        }
    }
    
    // Output based on the number of solutions
    if (solutions.size() == 1) {
        cout << solutions[0].first << " " << solutions[0].second << '\n';
    } else {
        cout << "?\n";
    }
}

int main() {
    cin >> n;
    while (n--) {
        solve();
    }
    return 0;
}
