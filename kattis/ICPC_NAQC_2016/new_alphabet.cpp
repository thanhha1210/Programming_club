#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef map<char, string> mc;

mc m;
string s;
int main() {
    m['a'] = "@";  m['b'] = "8";  m['c'] = "(";  m['d'] = "|)"; 
    m['e'] = "3";  m['f'] = "#";  m['g'] = "6";  m['h'] = "[-]";
    m['i'] = "|";  m['j'] = "_|";  m['k'] = "|<";  m['l'] = "1"; 
    m['m'] = "[]\\/[]";  m['n'] = "[]\\[]";  m['o'] = "0";  m['p'] = "|D";
    m['q'] = "(,)";  m['r'] = "|Z";  m['s'] = "$";  m['t'] = "']['"; 
    m['u'] = "|_|";  m['v'] = "\\/";  m['w'] = "\\/\\/";  m['x'] = "}{";
    m['y'] = "`/";  m['z'] = "2";

    rep(i, 0, 26) {
        m['A' + i] = m ['a' + i];
    }
    getline(cin, s);
    rep(i, 0, s.length()) {
        if (m.find(s[i]) != m.end()) {
            cout << m[s[i]];
        }
        else if (s[i] == '\n') {
            break;
        }
        else 
            cout << s[i];
        
    }
    
}