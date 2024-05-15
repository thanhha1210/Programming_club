#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;

void solve(int n, int m, vi a, vi b) {
    int i = 0, j = 0, d = 0;
    while (i < n && j < m) {
        if (abs(a[i] - b[j]) <= 1) {
            d++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) {
            i++;
        }
        else if (a[i] > b[j]) {
            j++;
        }
    }
    cout << d << endl;
}

int main() {
    
    int n, m;
    
    cin >> n;
    vi a(n);
    rep(i, 0, n)
        cin >> a[i];
    
    cin >> m;
    vi b(m);
    rep(i, 0, m)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    solve(n, m, a, b);

}
