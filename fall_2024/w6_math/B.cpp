#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
const int MAX_N = 1e6 + 7;
typedef long long ll;
typedef vector<long long> vll;
typedef vector<bool> vb;
ll a, t;
vb p;
vll d;

void createPrime() {
    p.assign(MAX_N, true);
    p[0] = false, p[1] = false;
    for (int i = 2; i * i < MAX_N; i++) {
        if (p[i]) {
            for(int j = i * i; j < MAX_N; j+= i) 
                p[j] = false; 
        }
        
    }
}

ll factor(ll n) {
    if (n <= 1) {
        return 1;
    }
    ll temp = 1, d = 2;
    while (n != 1) {
        if (n % d == 0) {
            ll k = 0;
            while (n % d == 0) {
                k++;
                n = n / d;
            }
            temp *= (k + 1);
        }
        if (p[n]) {
            temp *= 2;
            n = 1;
        }
        d++;
    }
    return temp;
}

void createDiv() {
    d.assign(MAX_N, 0);
    rep(i, 1, MAX_N) {
        d[i] = factor(i);
    }
}


int main() {
    createPrime();
    createDiv();

    ll t, a;
    cin >> t;
    while (t--) {
        cin >> a;
        cout << d[a] << '\n';
    }
}