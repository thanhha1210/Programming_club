#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rep_rev(i, j, n) for (int i = n; i >= j ; i--)
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int solve(string s, string t) {
    int n = s.length(), m = t.length(), maxx = 0;
    vvi dp(n + 1, vi(m + 1, 0));
    rep_rev(i, 0, n - 1) {
        rep_rev(j, 0, m - 1)
            if (s[i] == t[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
                if (dp[i][j] > maxx) {
                    maxx = dp[i][j];
                }
            }
            else 
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
    }
    
    return maxx;
}

void takeInput(string& t) {
    string s;
    while (getline(cin, s)) {
        if (s.empty()) { 
            break; 
        }
        rep(i, 0, s.length()) {
            if (isalpha(s[i])) 
                 t += static_cast<char>(tolower(s[i]));
        }
    }
}



int main() {
    string t;
    takeInput(t);
    string s = string(t.rbegin(), t.rend());
    cout << s.length() - solve(s, t);
}
