#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef map<char, ll> mcll;
typedef map<ll, char> mllc;

ll n, group_count;
string s;
vvll mx, es, res;
mcll mp;
mllc mp_rev;

void createMap() {
    rep(i, 0, 26) {
        mp[(char)('A' + i)] = i;
    }
    rep(i, 0, 10) {
        mp[(char)('0' + i)] = 26 + i;
    }
    mp[' '] = 36; 

    for (auto i : mp) {
        mp_rev[i.second] = i.first;
    }
}

void mulMatrix() {
    res.assign(group_count, vll(n, 0));

    rep(g, 0, group_count) {
        rep(i, 0, n) {
            ll sum = 0;
            rep(j, 0, n) {
                sum += mx[i][j] * es[g][j];
            }
            res[g][i] = sum % 37; 
        }
    }

    rep(i, 0, group_count) {
        rep(j, 0, n) {
            cout << mp_rev[res[i][j]];
        }
        // cout << '\n';
    }
    cout << '\n';
}

int main() {
  
    cin >> n;
    mx.assign(n, vll(n));
    rep(i, 0, n) rep(j, 0, n) cin >> mx[i][j];

    // Clear the newline character left by cin before using getline
    cin.ignore();

    getline(cin, s);

    while (s.length() % n != 0) {
        s += ' ';
    }
    createMap();
    group_count = s.length() / n;
    es.assign(group_count, vll(n));
    for (ll i = 0; i < group_count; i++) {
        for (ll j = 0; j < n; j++) {
            es[i][j] = mp[s[i * n + j]];
        }
    }

    // Perform matrix multiplication and print the result
    mulMatrix();
    return 0;
}
