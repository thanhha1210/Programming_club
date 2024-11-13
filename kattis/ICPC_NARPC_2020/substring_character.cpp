#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef set<char> sc;
typedef set<string> ss;

string s;
sc chars, temp;
ss res;

void solve() { 
    rep(i, 0, s.size()) {
        temp.clear();
        rep(j, i, s.size()) {
            if (i != j && s[j] == s[i]) {
                break;
            }
            else {
                temp.insert(s[j]);
                if (temp.size() == chars.size() && (i != 0 || j != s.size() - 1)) {
                    res.insert(s.substr(i, j - i + 1));
                    break;
                }
            }
        }
    }
    cout << res.size() << '\n';
}

int main() {
   
    while (cin >> s) {
        chars.clear();
        res.clear();
        rep(i, 0, s.size()) {
            chars.insert(s[i]);
        }
        solve();
    }
}
