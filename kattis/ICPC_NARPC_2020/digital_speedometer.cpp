#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<double> vd;


double f, r, init, s;
vd a;

int main() {
    cin >> f >> r >> init ;
    a.push_back(init);
    cout << init << '\n';
    while (cin >> s) {
        ll i = floor(s), j = ceil(s);
        if (i == 0) {
            cout << 1 <<'\n';
        }
        else if (s <= i + f) {
            cout << i << '\n';
        } 
        else if (s >= i + r) {
            cout << j << '\n';
        }
        else {
            for (int k = a.size() - 1; k >= 0; k--) {
                if (a[k] < i + f) {
                    cout << i << '\n';
                    break;
                }
                else if (a[k] > i + r) {
                    cout << j << '\n';
                    break;
                }
                else {
                    continue;
                }
            }
        }
        a.push_back(s);
    }

}