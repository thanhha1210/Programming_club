#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;
typedef vector<vector<long long>> vvll;
typedef vector<char> vc;

int n;
string s, t1, t2;
vvll dp;

void solve() {
   rep(i, 1, n + 1) {
        rep(j, 1, n + 1) {
            if (t1[i - 1] == t2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
           
        }
    }
    cout << n - dp[n][n];
}

int main() {
    while (getline(cin, s)) { 
        if (s.empty()) { 
            break; 
        } 
        else {
            rep(i, 0, s.length()) {
                if (('a' <= s[i] && s[i] <= 'z') || ('A' <= s[i] && s[i] <= 'Z')) {
                    t1 = t1 + string(1, tolower(s[i]));
                    t2 = string(1, tolower(s[i])) + t2;
                }
            }
        }
    } 
    n = t1.length();
    dp.assign(n + 1, vll(n + 1, 0));
    solve();
    return 0;
}