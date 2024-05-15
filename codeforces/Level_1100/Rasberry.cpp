#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, k, x, d, maxx, even;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k;
        even = 0;
        maxx = 10;
        for (int i = 0; i < n; i++) {
            cin >> x;
            if (x % 2 == 0)
                even += 1;
            d = ceil(x * 1.0 / k) * k - x;
            maxx = min(maxx, d);
        }
        if (k == 4) {
            if (n == 1)
                cout << maxx << endl;
            else {
                if (even == 1)
                    cout << min(1, maxx) << endl;
                else if (even == 0)
                    cout << min(2, maxx) << endl;
                else    
                    cout << 0 << endl;
            }
            
        }
        else
            cout << maxx << endl;
    }
}
