#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
ll n, x;
vll dp;


int main() {
    cin >> n;
    rep(i, 0, n) {
        cin >> x;
        auto it = lower_bound(dp.begin(), dp.end(), x);  
        if (it == dp.end()) {
            dp.push_back(x);
        }
        else {
            *it = x;
        }
    }
    cout << dp.size() << '\n';
    return 0;
}