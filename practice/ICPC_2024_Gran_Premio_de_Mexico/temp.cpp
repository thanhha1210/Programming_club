#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<pair<string, string>> vpss;

ll n;
string s;
vpss name;

int main() {
    cin >> n;
    rep(i, 0, n) {
        cin >> s;
        string t1 = s.substr(0, 4);
        string t2 = s.substr(4, 3);
        name.push_back({t2, t1});
    }
    sort(name.begin(), name.end());
    cout << name[0].second << name[0].first;
}