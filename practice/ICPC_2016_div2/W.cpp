#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
ll a[6], b[6], cnt = 0, sum = 36;


int main() {
    rep(i, 0, 6) cin >> a[i];
    rep(i, 0, 6) cin >> b[i];

    rep(i, 0, 6) 
        rep(j, 0, 6) {
            if (a[i] > b[j])
                cnt++;
            else if (a[i] == b[j]) 
                sum--;
            }
        
    cout << fixed << setprecision(5) << 1.0 * cnt / sum;
}