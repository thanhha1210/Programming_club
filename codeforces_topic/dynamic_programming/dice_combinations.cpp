#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
ll n;
vll a = {0, 1, 2, 4, 8, 16, 32};
const ll MOD = 1e9 + 7;


int main() {
    cin >> n;
    rep(i, 7, n + 1) {
        a.emplace_back((a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6]) % MOD);
    }
    cout << a[n] << '\n';
    
}