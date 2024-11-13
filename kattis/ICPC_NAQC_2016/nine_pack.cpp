#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
const ll INF = 1e9 + 7;
ll n, m, sum1 = 0, sum2 = 0, s, res = INF;
vll a, b, dp1, dp2;

void create() {
    
    dp1.assign(s + 1, INF);
    dp2.assign(s + 1, INF);
    dp1[0] = 0, dp2[0] = 0;
  
    rep(i, 0, n) {
        for(int j = s + 1; j >= a[i]; j--) {
            dp1[j] = min(dp1[j], dp1[j - a[i]] + 1);
        }
    }
    rep(i, 0, m) {
         for(int j = s + 1; j >= b[i]; j--) {
            dp2[j] = min(dp2[j], dp2[j - b[i]] + 1);
        }
    }
    rep(i, 1, s + 1) {
        if (dp1[i] != INF && dp2[i] != INF) {
            res = min(res, dp1[i] + dp2[i]);
        }
     
    }
    
    if (res == INF) { 
        cout << "impossible\n";
    }
    else {
        cout << res;
    }
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
        sum1 += a[i];
    }

    cin >> m;
    b.resize(m);
    rep(i, 0, m) {
        cin >> b[i];
        sum2 += b[i];
    }
    
    s = sum1 + sum2;
    create();
}