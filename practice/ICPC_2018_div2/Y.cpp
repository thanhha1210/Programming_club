#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<int> vi;
typedef long long ll;

ll K, P, X;
double price = 1e13 + 6;

double f(ll n) {
    return n * X + P * (K * 1.0 / n);
}

int main() {
    cin >> K >> P >> X;     // K - work, P - price, X - fixed
    rep(i, 1, 10001) {
        if (price > f(i))
            price = f(i);
    }
    cout << fixed << setprecision(3) << price;
}