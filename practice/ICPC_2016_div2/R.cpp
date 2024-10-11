#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
int a, b, c;
string s;
int main() {
    getline(cin, s);
    a = s[0] - '0';
    b = s[4] - '0';
    c = s[8] - '0';
    if (a + b == c)
        cout << "YES";
    else 
        cout << "NO";
}