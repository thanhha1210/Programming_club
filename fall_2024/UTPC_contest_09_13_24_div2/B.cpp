#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, k, maxx = 0;
string s;
vll x;

void solve() {
    if (k >= x.size()) {
        cout << n << " ";
        return;
    }
    maxx = max(n - x[x.size() - k], x[k]); // from head, from tail
    rep(i, 0, x.size()) {
        if (i + k < x.size()) {
            maxx = max(maxx, x[i + k] - x[i]);
            if (i + k + 1 < x.size())
                maxx = max(maxx, x[i + k + 1] - x[i] - 1);
        }
        else 
            break;
    }
}

int main() {
    cin >> n >> k;
    cin >> s;
    rep(i, 0, n) {
        if (s[i] == '2') 
            x.push_back(i);
    }
    solve();
    cout << maxx;

}