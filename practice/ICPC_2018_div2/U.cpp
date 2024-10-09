#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<double> vd;

double minX = LONG_LONG_MAX, sum = 0.0;
vd pr(7);

int main() {
    rep(i, 1, 7) {
        cin >> pr[i];
        sum += pr[i] * i;
    }
    rep(i, 1, 7) {
        if (pr[i] != 0) {
            double diff = abs(((3.5 - (sum - i * pr[i]))/ pr[i]) - i);
            if (diff < minX) minX = diff; 
        }
    }
    cout << fixed << setprecision(3) << minX;
}