#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;


const long long INF = 1e9;
ll t, n, m, a, b, c, cnt = 0;
vvd d;


int main() {
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        d.clear();
        d.assign(n + 1, vd(n + 1, 0));

        rep(i, 1, n + 1) {
            d[i][i] = 1.0;
        }

        cin >> m;
        rep(i, 0, m) {
            cin >> a >> b >> c;
            double pr = c / 100.0;
            d[a][b] = max(d[a][b], pr);
            d[b][a] = max(d[b][a], pr);
        }
        rep(k, 1, n + 1) {
            rep(i, 1, n + 1) {
                rep(j, 1, n + 1) {
                    d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
                }
            }
        }
        cout << fixed << setprecision(6) << d[1][n] * 100.0 << " percent\n";
    }
}