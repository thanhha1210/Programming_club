#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;

ll n, k;
vll a;
vvll bi, b;
const ll LLMIN = -1e18;

// bi(i, j) = max sum of j sub arrays in A[1 : i] that include ith element
// b(i, j)  = max sum of j sub arrays in A[1 : i] overall (not necessarily include ith element)

ll maxSub() {
    b.assign(n + 1, vll(k + 1, -1e18));
    bi.assign(n + 1, vll(k + 1, -1e18));
    rep(i, 0, n + 1) {  // case no sub array
        b[i][0] = 0;
        bi[i][0] = 0;
    }
    // => mean form 0 if have i sub array, but no elem can't have i sub array, INCORRECT
    // rep(i, 0, k + 1) {   
    //     b[0][i] = 0; bi[0][i] = 0; 
    // }
    rep(i, 1, n + 1) {
        rep(j, 1, k + 1) {
            if (i >= j) {   // ensure # of element >= # of sub array
                // add i to prev sub array / create a new sub array 
                bi[i][j] = max(bi[i - 1][j], b[i - 1][j - 1]) + a[i];
                // either exclude a[i], include a[i]
                b[i][j] = max(b[i - 1][j], bi[i][j]);
            }
        }
    }
    return b[n][k];
}


int main() {
    cin >> n >> k;
    a.resize(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    cout << maxSub();
}   