#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

string s, t;
bool check = false;
bool checkPalindrome(const string& s) {
    rep(i, 0, s.size() / 2) {
        if (s[i] != s[s.size() - 1 - i])
            return false;
    }
    return true;
}

int main() {
    cin >> s;
    int n = s.length();
    rep(i, 0, n) {
        if (!check) {
            rep(j, 1, n - i) {
                t = s.substr(i, j);
                if (checkPalindrome(t) && (t.size() % 2 == 0)) {
                    cout << "Or not.";
                    check = true;
                    break;
                }
            }
        }  
    }
    if (!check) {
        cout << "Odd.";
    }
}