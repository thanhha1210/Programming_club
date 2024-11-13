#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<vector<long long>>> vvvll;

ll n, k1, INF = 1e9;
vvll a;
vvvll dp;

ll fmin(ll a, ll b, ll c) {
    return min({a, b, c});
}

// Function to compute the maximum value after closing k rooms
ll f(ll k, ll r, ll c) {
    // If no rooms left to close, we are done
    if (k == 0) return 0;
    // If we are out of rows, return a large negative value (impossible state)
    if (r < 0) return INF;
    // Use memoized result if already computed
    if (dp[k][r][c] != -1) return dp[k][r][c];

    // Extract value of the current room
    ll room_val = a[r][c];
    
    // Recurrence: close the current room or not, while considering passage constraints
    ll close_current = f(k - 1, r - 1, c) + room_val; // Close current room
    ll skip_current1 = f(k, r - 1, c);                     // Skip current room
    ll skip_current2 = f(k, r - 1, 1 - c);
    
    dp[k][r][c] = fmin(close_current, skip_current1, skip_current2);
    return dp[k][r][c];
}

// Function to find the optimal solution for a single gallery instance
ll solve() {
    ll sum = 0;
    // Calculate the total sum of all room values
    rep(i, 0, n) {
        sum += a[i][0] + a[i][1];
    }
    // Subtract the maximum value we can obtain after closing k rooms
    return sum - min(f(k1, n - 1, 0), f(k1, n - 1, 1));
}

int main() {
    while (true) {
        cin >> n >> k1;
        if (n == 0 && k1 == 0) break; // End of input
        dp.clear();
        a.clear();
        dp.assign(k1 + 1, vvll(n, vll(2, -1))); // -1 is uncomputed
        a.assign(n, vll(2));
        
        rep(i, 0, n) {
            cin >> a[i][0] >> a[i][1];
        }
        cout << solve() << endl;
    }
    return 0;
}
