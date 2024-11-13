#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

char x;
ll n, m, a, b, c;
struct cmd {
    char op;
    ll deg;
    ll col;
};
struct pt {
    ll x, y, z;
};
vector<cmd> st;

void find(ll a, ll b, ll c) {
    vector<cmd> temp = st;
    reverse(temp.begin(), temp.end());
    rep(i, 0, temp.size()) {
        for (int d = 0; d < temp[i].deg; d += 90) {
            if (temp[i].op == 'x') {
                if (a > temp[i].col) {
                    int d = b;
                    b = n + 1 - c;
                    c = d;
                }
            }
            else if (temp[i].op == 'y') {
                if (b > temp[i].col) {
                    int d = a;
                    a = c;
                    c = n + 1 - d;
                }
            }
            else {
                if (c > temp[i].col) {
                    int d = b;
                    b = a;
                    a = n + 1 - d;
                }

            }
        }
    }
    cout << a + n * (b - 1) + n * n * (c - 1) << '\n';
}



int main() {
    cin >> n >> m;

    rep(i, 0, m) {
        cin >> x >> a >> b;
        if (x != 'q') {
            st.push_back({x, a, b});
        }
        else {
            cin >> c;
            find(a, b, c);
        }

    }

}