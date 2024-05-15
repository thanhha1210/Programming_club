#include <bits/stdc++.h>    
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n + 1, 0);
        rep(i, 0, n) {
            cin >> x;
            a[x]++;
        }

        int d = 0;
        rep(i, 0, n + 1) {
            if (a[i] == 1)
                d++;
            if (a[i] == 0 || d == 2) {
                cout << i << endl;
                break;
            }
        }
    }
}