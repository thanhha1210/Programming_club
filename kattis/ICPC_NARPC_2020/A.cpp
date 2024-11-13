#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

double r, s, v;
ll u, l;

int main() {
    while (cin >> r >> s) {
        v = sqrt((r * (s + 0.16)) / 0.067);
        u = ceil(v); 
        l = floor(v);
        if (abs(u - v) <  abs(l - v)) {
            cout << u << '\n';
        }
        else {
            cout << l << '\n';
        }
    }
    return 0;
}
