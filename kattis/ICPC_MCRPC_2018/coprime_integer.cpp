#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;

const ll MAXN = 1e7 + 7;
ll mu[MAXN], pri[MAXN], tot, zhi[MAXN];

// Function to calculate the Möbius function using a sieve approach
// This will do inclusion, exclusion
void sieve(ll n) {
    zhi[1] = mu[1] = 1; // Initialize for 1
    rep(i, 2, n + 1) {
        if (!zhi[i]) {  // If 'i' is a prime number
            pri[++tot] = i; 
            mu[i] = -1; // Prime numbers have Möbius function -1
        }
        // Mark multiples of primes and compute their Möbius values
        for (ll j = 1; j <= tot && i * pri[j] <= n; j++) {
            zhi[i * pri[j]] = 1;
            if (i % pri[j]) 
                mu[i * pri[j]] = -mu[i]; // Flip sign if no common factors
            else {
                mu[i * pri[j]] = 0; // If divisible by prime squared
                break;
            }
        }
    }
}

int main() {
    sieve(10000000); // Precompute Möbius function up to 10^7
    ll a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;

    // Calculate the number of coprime pairs
    for (ll i = 1; i <= min(b, d); i++) {
        ans += mu[i] * ((b / i) - (a - 1) / i) * ((d / i) - (c - 1) / i);
    }
    cout << ans << endl;
}
