#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

ll n, c1, c2;
char cur;
string s;

int main() {
    cin >> n >> s;
    cur = s[0];
    rep(i, 1, n) {
        if (s[i] == cur) {
            continue;
        }
        else {
            if (s[i] == '1') {
                c2++;
                cur = s[i];
            }
            else {
                c1++;
                cur = s[i];
            }
        }
    }
    if (s[0] == '0') {
        c1++;
    }
    else {
        c2++;
    }
    cout << min(c1, c2);
}
