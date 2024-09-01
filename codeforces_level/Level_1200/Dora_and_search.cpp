#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;

void solve(int& n, vi& a) {

    int l = 0, r = n - 1;
    int min = 1, max = n;
    while (l < r) {
        if (a[l] == min || a[l] == max){
            if (a[l] == min) {
                l++;
                min++;
            }
            else {
                l++;
                max--;
            }
        }
        if (a[r] == min || a[r] == max){
            if (a[r] == min) {
                r--;
                min++;
            }
            else {
                r--;
                max--;
            }
        }
        if (a[l] != min && a[l] != max && a[r] != min && a[r] != max) {
            cout << l + 1 << " " << r + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
    return;

}

int main() {

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n);
        rep(i, 0, n)
            cin >> a[i];
        solve(n, a); 
    }

}