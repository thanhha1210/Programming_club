#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<long long> vll;

typedef long long ll;

ll n, x0, z1, index, dis;
vll x, y;
double minx = LONG_LONG_MAX;

int main() {
    cin >> n >> x0 >> z1;
    x.resize(n);
    y.resize(n);
    rep(i, 0, n) {
        cin >> x[i] >> y[i];
        dis = (x[i] - x0) * (x[i] - x0) + (y[i] - z1) * (y[i] - z1);
        if (dis < minx) {
            minx = dis;
            index = i;
        }
        else if (dis == minx) {
            if (x[i] < x[index]) {
                index = i;
            }
            else if (x[i] < x[index] && y[i] < y[index]) {
                index = i;
            }
        }
    }
    cout << x[index] << " " << y[index];
}

