#include <bits/stdc++.h>    
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;

void solve(vi& a, int& n) {

    
}

int main() {
    int t, n, x;
    cin >> t;
    while (t--) {
        cin >> n;
        vi a(n, 0);
        rep(i, 0, n) {
           cin >> a[i];
        }
        
        sort(a.begin(), a.end());

        solve(a, n);
    }
}