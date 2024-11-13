#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c, t;

const ll INF = 1e9 + 7;
// compute a^n
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        // bitwise AND operation that checks if the least significant bit of b is 1
        //If b is odd, b & 1 will be 1 (true), and if b is even, b & 1 will be 0 (false).
        if (b & 1)         
            res = res * a;
        a = a * a;
        // b >>= 1 is a bitwise right shift operation that divides b by 2, discarding the least significant bit.
        // each time b is right-shifted, it effectively moves to the next bit of b in its binary representation
        b >>= 1;
    }
    return res;
}


// Effective computation of large exponents modulo a number. 
// Compute (x^n) mod m. Fact: a.b === ((a mod m) . (b mod m)) (mod m)
ll binpow2(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}


// (a ^ (b ^ c)) MOD INF, then b^c can be reduce by M(INF), where M is Euler's Totient function.
// M(x) is calculated by : 1. Factor x = (x1 ^ p1) * (x2 ^ p2) * ..., xi is prime
// M(x) = x * (1 - 1/x1) * (1 - 1/x2) * ...
// Property: If x is prime, M(x) = x - 1
int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b >> c;
        ll temp = binpow2(b, c, INF - 1);
        cout << binpow2(a, temp, INF) << '\n';
    }
}