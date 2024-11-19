#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

vll a;
ll n, p;
string s, t;
map<ll, ll> m;



void rotate(ll l, ll r) {   // l is win, r is loss
    ll i1 = m[l];
    ll i2 = m[r];
    if (i1 < i2) {
        return;
    }
    ll temp = a[i2];
    rep(j, i2, i1){
        a[j] = a[j + 1];
        m[a[j]] = j;
    }
    a[i1] = temp;
    m[a[i1]] = i1;
}

int main() {
    cin >> n >> p;
    a.resize(n + 1);
    rep(i, 1, n + 1) {
        a[i] = i;
        m[i] = i;
    }

    rep(i, 0, p) {
        cin >> s >> t;
        ll win = stoi(s.substr(1, s.length() - 1)); // w is winning tem
        ll loss = stoi(t.substr(1, t.length() - 1)); // l is losing team
        rotate(win, loss);
        // rep(i, 1, n + 1) 
        //     cout << "T" << a[i] << " ";
        // cout << '\n';
        // rep(i, 1, n + 1) 
        //     cout << m[i] << "  ";
        // cout << '\n';
    }
    
    rep(i, 1, n + 1) {
        cout << "T" << a[i] << " ";
    }

}