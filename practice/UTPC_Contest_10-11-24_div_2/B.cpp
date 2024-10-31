#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, t, sum = 0, cnt = 0;
vll c ;

int main() {
    cin >> n >> t;
    c.resize(n);
    rep(i, 0, n) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());

    rep(i, 0, n) {
        sum += c[i];
        if (sum <= t) {
            cnt++;  
        }
        else {
            break;
        }
    }  
    cout << cnt; 
}
