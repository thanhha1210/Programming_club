#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i <n; i++)
typedef long long ll;
ll n;
double X, v, a, b, c, avg_y, x_velocity = -1;

int main() {
    cin >> n >> X >> v;
    rep(i, 0, n) {
        cin >> a >> b >> c;
        avg_y += (b - a) * c * 1.0 /  X;
    }
    if (abs(avg_y) < v) 
        x_velocity = sqrt(v * v - avg_y * avg_y);
    if (x_velocity < 0 || x_velocity * 2.0 < v)
        cout << "Too hard\n";
    else 
        cout << fixed << setprecision(3) << 1.0 * X / x_velocity;
}
