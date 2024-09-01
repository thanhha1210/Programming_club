#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, j, n) for (int i = j; i < n; i++)

int main() {

    int t, n, x, d, maxx;
    bool flag;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        flag = false;
        maxx = 0;
        rep(i, 0 , n) {
            cin >> x;
            maxx = x > maxx ? x : maxx;
            if (d == x)
                flag = true;
        }
        if (d == 0)
            cout << 0 << '\n';
        else if (flag) {
            cout << 1 << '\n';
        }
        else {
            cout << max(2, (d + maxx - 1)/ maxx);   // If ceil(d/maxx) >= 2, we can reach (d, 0) in that number of hops by hopping to the right  [ceil(d/y) - 2] times using y then the last 2 hops for up to 2y additional distance
            cout << '\n';
        }
      
    }

}