#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
vector<int> dp; 
int maxx = 0;
string s;
int main() {
    cin >> s;
    s = "0" + s;
    dp.assign(s.length(), 0);

    rep(i, 1, s.length()) {
        char c = s[i];
        for (int j = i - 1; j >= 0; j--) {
            if (c > s[j])
                dp[i] = max(dp[i], dp[j] + 1);
            maxx = maxx < dp[i] ? dp[i] : maxx;
        }
    }

    cout << 26 - maxx;

} 
