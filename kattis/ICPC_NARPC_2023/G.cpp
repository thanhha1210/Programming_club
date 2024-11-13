#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

string s;
ll maxn = 0, a = 0, b = 0, c = 0;
vvll dp;

int main() {
    cin >> s;
    dp.assign(s.length(), vll(3, 0));
    rep(i, 0, s.length()) {
        if (s[i] == 'A') a++;
        if (s[i] == 'B') b++;
        if (s[i] == 'C') c++;

       ll k = max(abs(a - b), max(abs(a - c), abs(b - c)));
       maxn = max(maxn, k);
    }
    cout << maxn;

}