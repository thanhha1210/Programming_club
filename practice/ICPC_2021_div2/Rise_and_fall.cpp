#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    for (int d = 0; d < n; d++) {
        cin >> s;
        int minx = 9;
        bool flag = false;
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i] < s[i - 1]) {
                flag = true;
                minx = min(minx, s[i] - '0');
            }
            if (!flag)
                cout << s[i];
            else if (flag) {
                cout << minx;
            }
            
        }
        cout << endl;
    }
}