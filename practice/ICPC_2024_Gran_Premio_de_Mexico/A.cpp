#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<pair<string, string>> vpss;
typedef vector<char> vc;
typedef long long ll;

vpss dic;
ll n, q;

string makeString(const string &s) {
    string t = s;
    sort(t.begin(), t.end());
    return t;
}

int search(const string &s) {
    string t = makeString(s);
    auto it = upper_bound(dic.begin(), dic.end(), make_pair(t, s));
    return distance(dic.begin(), it);
}

int main() {
    cin >> n;
    dic.resize(n);
    rep(i, 0, n) {
        string s;
        cin >> s;
        dic[i] = {makeString(s), s};
    }
   
    sort(dic.begin(), dic.end());
    
    cin >> q;
    rep(i, 0, q) {
        string s;
        cin >> s;
        cout << search(s) << '\n';
    }

    return 0;
}
