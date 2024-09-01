#include <bits/stdc++.h>    
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rep_reverse(i, n, j) for (int i = n; i >= j; i--)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<int> vi;

int f(string& s) {
    int res = 0;
    rep_reverse(i, s.length() - 1, 0) {
        if (s[i] == '0') 
            res++;
        else
            break;
    }
    return res;
}

int main() {
    int t, n, k, m;
    string s;
    cin >> t;
  
    while (t--) {
        cin >> n >> m;
        vi a;
        k = 0;
        rep(i, 0, n) {
            cin >> s;
            k += s.length();
            if (f(s) > 0)
                a.emplace_back(f(s));
        }
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());

        rep(i, 0, a.size()) {
            if (i % 2 == 0)
                k -= a[i];
        }


        if (k > m)
            cout << "Sasha" << endl;
        else
            cout << "Anna" << endl;
    
    }
}