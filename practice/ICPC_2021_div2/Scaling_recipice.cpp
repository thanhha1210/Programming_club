#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, a;
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cout << a * y / x << endl;
    }
}