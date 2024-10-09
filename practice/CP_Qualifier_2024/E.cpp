#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
int n, x, cnt = 0, maxn;
vi num, res;

int main() { 
    cin >> n;
    num.assign(51, 0);
    rep(i, 0, n * 10 * 5) {
        cin >> x;
        num[x]++;
    }
    maxn = n * 50;
    rep(i, 1, 51) {
        if (num[i] * 1.0 / (n * 10.0) > 0.2) 
            res.push_back(i);
    }
    sort(res.begin(), res.end());
    if (res.size() == 0) {
        cout << -1;
    }
    else {
        rep(i, 0, res.size()) {
            cout << res[i] << ' ';
        }
    }
   
}