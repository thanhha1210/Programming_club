#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rrep(i, n, j) for (int i = n; i >= j; i--)
typedef long long ll;
typedef vector<int> vi;
typedef vector<char> vc;

string s;
bool check = false;
char odd, c;
vi fre;
vc res;
int main() {
    fre.assign(26, 0);
    cin >> s;
    rep(i, 0, s.length()) {
        fre[s[i] - 'a']++;
    }

    rep(i, 0, 26) {
        char c = 'a' + i;
        if (fre[i] % 2 != 0) {
            odd = i + 'a';
            check = true;
        }
        fre[i] /= 2;
        
        int k = fre[i];
        while (k > 0) {
            cout << c;
            k--;
        }
    }
    if (check)
        cout << odd;

    rrep(i, 25, 0) {
        char c = 'a' + i;
        int k = fre[i];
        while (k > 0) {
            cout << c;
            k--;
        }
    }
    

}