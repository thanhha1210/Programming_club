#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
const ll INF = 1e9 + 7;

ll res[];

struct node {
    ll a[8];
};

node press(node st, ll idx) {
    int c = st.a[i];   // key press
    node k = st;       // temp node
    if (c == 0) {   // A
        if (idx != 0) k.a[idx - 1] = (k.a[idx - 1] + 1) % 6;
        if (idx != 7) k.a[idx + 1] = (k.a[idx + 1] + 1) % 6;
    }
    else if (c == 1) {  // B
        if (idx != 0 && idx != 7) 
            k.a[idx + 1] = k.a[idx - 1];
    }
    else if (c == 2) { // C
        k.a[7 - idx]  = (k.a[7 - idx] + 1) % 6; 
    }
    else if (c == 3) {  // D
        if (idx <= 3) {
            rep(i, 0, idx) {
                k.a[i] = (k.a[i] + 1) % 6;
            }
        }
        else {
            rep(i, idx + 1, 8) {
                k.a[i] = (k.a[i] + 1) % 6;
            }
        }
    }
    else if (c == 4) {  // E

    }
    else {  // F
        if (idx % 2 != 0) {}
    }
    return temp;
}

ll f(const ll& a[]) {
    ll temp = 0;
    rep(i, 0, 8) {
        temp += 7 * temp + a[i];
    }
    return temp;
}

int main() {
    string s, t;
    node rs, rt;
    cin >> s >> t;
    memset(res, INF, 1e7 + 9);
    rep(i, 0, s.length()) rs.a[i] = s[i] - 'A';
    rep(i, 0, t.length()) rt.a[i] = t[i] - 'A';
    res[f(rs.a)] = 0;
    queue<node> q;
    q.push(rs);

    while (!q.empty) {
        node s = q.
        rep(i, 0, 8) {
            press()
        }
    }



}