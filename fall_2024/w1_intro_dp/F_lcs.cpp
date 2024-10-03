#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rep_rev(i, j, n) for (int i = n; i >= j ; i--)
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<vector<char>> vvc;
typedef vector<char> vc;

void solve(string s, string t) {
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
    
    int k = 0, i = 0, j = 0;
    vc res(dp[0][0]);
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            res[k++] = s[i];
            i++;
            j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1])
            i++;
        else
            j++;
    }
    rep(i, 0, dp[0][0]) {
        cout << res[i];
    }

}
int main() {
    string s, t;
    cin >> s >> t;
    solve(s, t);
}