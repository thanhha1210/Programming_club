#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<string> vs;

vs a, b;
int n;

bool isValidISBN10(string s) {
    int d = 0, k = 10, sum = 0;
    bool checkX = false;

 
    if (s[0] == '-' || s[s.size() - 1] == '-')
        return false;

    rep(i, 0, s.size()) {
        if (s[i] == '-') {
            if (i > 0 && s[i - 1] == '-')
                return false;
            d++;
        } 
        else if (s[i] >= '0' && s[i] <= '9') {
            sum += k * (s[i] - '0');
            k--;
        } 
        else if (s[i] == 'X' && k == 1) {
            sum += 10; 
            k--;
        }
        else {
            return false;
        }
    }
    
    if (d == 3 && s[s.size() - 2] != '-') {
        return false;
    }

    return (sum % 11 == 0) && (d <= 3) && (k == 0);
}

string convertISBN10to13(string s) {
    string t = "978-" + s.substr(0, s.size() - 1);
    int sum = 0, k = 0;

   
    rep(i, 0, t.size()) {
        if (t[i] >= '0' && t[i] <= '9') {
            if (k % 2 == 0) sum += 1 * (t[i] - '0');
            else sum += 3 * (t[i] - '0');
            k++;
        }
    }
    int last = sum % 10;
    last = (last == 0) ? 0 : 10 - last;

    t = t + to_string(last);
    return t;
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    
    rep(i, 0, n) 
        cin >> a[i];
    
    rep(i, 0, n) {
        if (isValidISBN10(a[i])) {
            b[i] = convertISBN10to13(a[i]);
        } 
        else {
            b[i] = "invalid";
        }
    }

    rep(i, 0, n) {
        cout << b[i] << '\n';
    }

    return 0;
}
