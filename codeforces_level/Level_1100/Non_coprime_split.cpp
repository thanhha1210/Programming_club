#include <bits/stdc++.h>
using namespace std;
void solve(long long& a, long long& b) {
    for (int i = a; i <= b; i++) {
        for(int j = 2; j <= trunc(sqrt(i)); j++) {
            if (i % j == 0) {
                int k = i / j;
                if (k > 1) {
                    cout << j << " " << (k - 1) * j << endl; 
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
    return;
}
int main() {
    long long t, a, b;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a >> b;
        solve(a, b);
    }
}