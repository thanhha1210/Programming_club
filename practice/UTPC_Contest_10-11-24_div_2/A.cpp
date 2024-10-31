#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, cnt = 1;
vll c;

int main() {
    cin >> n;
    c.resize(n + 1);
    c[1] = 1;
    rep(i, 2, n + 1) {
        c[i] = ((4 * c[i - 1]) ^ (i - 1)) % 6;
        if (c[i] == 1){
            cnt++;
        }
    }
    cout << cnt;
}
