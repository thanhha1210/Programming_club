#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll n;
string s, t, t1, t2;


bool check() {
    string temp = s;
    reverse(temp.begin(), temp.end());
    rep(i, 0, n) {
        if (t.substr(i, temp.length()) == temp)
            return true;
    }

    return false;
}



int main() {
    cin >> s;
    n = s.length();
    t = s + s;
    if (check()) cout << 1;
    else cout << 0;
}