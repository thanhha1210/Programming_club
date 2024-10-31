#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef vector<int>vi;

int n, k, pre, d = 0; // d > 0 : inc, d < 0: dec
vi a;
stack<int> res;

void solve() {
    res.push(a[0]);
    k = 1;
    while (k < n) {
        int m = res.top();
        if (a[k] > m) {
            if (d > 0) {
                res.pop();
                pre = res.top();
                res.push(a[k]);
                d = a[k] - pre;
            }
            else if (d <= 0) {
                res.push(a[k]);
                d = a[k] - m;
            }
            
        }
        else if (a[k] < m) {
            if (d < 0) {
                res.pop();
                pre = res.top();
                res.push(a[k]);
                d = a[k] - pre;
            }
            else if (d >= 0){
                res.push(a[k]);
                d = a[k] - m;
            }
            
        }
        k++;
    }    
}

int main() {
    cin >> n;
    a.resize(n);
    rep(i, 0, n) cin>> a[i];
    
    if (n == 1) {
        cout << 1;
    }
    else {
        solve();
        cout << res.size();
    }
    

}