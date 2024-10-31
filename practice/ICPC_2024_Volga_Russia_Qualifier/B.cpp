#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

string s, t;
int cnt = 0, res;

int main() {
    cin >> s >> t;
    rep(i, 0, min(s.size(), t.size())) {
        if (s[i] == t[i]) {
            cnt++;
        }
        else 
            break;
    }
    cout << s.size() + t.size() + 1 - cnt;  
}