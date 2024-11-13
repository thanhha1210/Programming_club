#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
int t;
string s, temp;
map<char, string> m;
int main() {
    m['0'] = "000"; m['1'] = "001"; m['2'] = "010"; m['3'] = "011"; 
    m['4'] = "100"; m['5'] = "101"; m['6'] = "110"; m['7'] = "111";
    cin >> t;
    while(t--) {
        cin >> s;
        temp = "";
        rep(i, 0, s.length()) {
            temp = temp + m[s[i]];
        }
        rep(i, 0, temp.length()) {
            if (temp[i] == '0') {
                cout << '-';
            }
            else {
                if (i % 3 == 0) cout << 'r';
                else if (i % 3 == 1) cout << 'w';
                else if (i % 3 == 2) cout << 'x';
            }
        }
        cout << '\n';
    }
}