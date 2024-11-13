#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<vector<vector<ll>>> vvvll;

string s;
ll n;
vvvll dp;  // DP table to store results (i, l, t)

// L(i, t) function based on current state and character at position i
ll L(ll i, ll t) {
    if (s[i] == '(' && t != 1) return 1;   // '(' and not inverting
    if (s[i] == ')' && t == 1) return 1;    // ')' and inverting
    return 0;  // Otherwise return 0
}

// Recursive function to fill dp table
ll f(ll i, ll l, ll t) {
    if (i == n - 1 && l == n / 2) {
        return dp[i][l][t] = 1;   
    }
    if (l < i - l) {
        return dp[i][l][t] = -1;   // false
    }
    else {
        ll result = -2;
        if (t == 0) {  // Before inversion state
            result = max(result, f(i, l, 1));
        } 
        else if (t == 1) {  // Inverting state
            result = max(result, f(i, l, 2));
        } 
        else if (t == 2) {  // After inversion state
            result = max(result, f(i + 1, l + L(i, t), t));
        }
        dp[i][l][t] = result;
        return result;
    }
}

void solve() {
    dp.assign(n + 1, vvll(n + 1, vll(3, -2)));  // Initialize DP table with -2 (unvisited)
    // Start the DP process from index 0 with 0 left parentheses and "Before" state
    if (f(0, 0, 0)) {
        cout << "possible" << endl;
    } 
    else {
        cout << "impossible" << endl;
    }
}

int main() {
    cin >> s;
    n = s.length();
    s = " " + s;
    // If the string length is odd, it's immediately impossible
    if (n % 2 != 0) {
        cout << "impossible" << endl;
    } 
    else {
        solve();
    }

    return 0;
}
