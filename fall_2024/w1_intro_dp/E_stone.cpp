#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, k;
vll a;
vll dp;

int main() {
    cin >> n >> k;
    a.resize(n);  
    rep(i, 0, n) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());  
    dp.resize(k + 1);         
    rep(i, 0, min(a[0], k + 1)) {
        dp[i] = 2; 
    }
    
    rep(i, a[0], k + 1) {
        rep(j, 0, a.size()) {
            if (a[j] <= i) {
                if (dp[i - a[j]] == 2) {  
                    dp[i] = 1;            
                    break;
                }
            } 
            else {
                break;  
            }
        }
        if (dp[i] == 0) dp[i] = 2;  
    }
    
    if (dp[k] == 2) {
        cout << "Second";
    }
    else {
        cout << "First";
    }
    return 0;
}
