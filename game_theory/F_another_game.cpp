#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

int main() {
    ll t, n, x;

    cin >> t;
    while (t--) {
        cin >> n;
        bool flag = false;
        rep(i, 0, n) {
            cin >> x;
            if (x % 2 != 0)
                flag = true;
        }
        cout << (flag== true ? "first" : "second");
        cout << endl;
    }

}