#include <bits/stdc++.h>
using namespace std;

long long MOD = 1000000007;
long long sumDivisor(int x) {
    long long cnt = 0;
    for (int i = 1; i < x; i++) {
        long long k = ((x / i) * i ) % MOD;
        cnt = (cnt + k) % MOD; 
    }
    return cnt;
}

int main() {
    long long n;
    cin >> n;
    cout << sumDivisor(n);
}