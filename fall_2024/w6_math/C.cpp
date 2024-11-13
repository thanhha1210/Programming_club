#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
const int INF = 1e9 + 7;
typedef long long ll;
typedef vector<long long> vll;
ll a, t;
string s;
vll d(26, 0);


int main() {
    cin >> s;
    rep(i, 0, s.size()) {
        d[s[i] - 'a']++;
    }
}