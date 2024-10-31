#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef multiset<long long> mll;

ll n, m, k;
mll a;

int main() {
    cin >> n >> m;
  
    rep(i, 0, n) {
        cin >> k;
        a.insert(-k);
    }
    rep(i, 0, m) {
        cin >> k;
        auto it = a.lower_bound(-k);
        if (it != a.end()) {
            cout << (-1) * (*it) << '\n';
            a.erase(it);    // if *it -> erase all same val
        }
        else {
            cout << "-1\n";
        }
    }
    return 0;

}
