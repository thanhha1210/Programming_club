#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


const long long INF = 1e12;
ll t, n, m, a, b, c, cnt = 1, sum = 0;
vvll d;

void floyd_warshall() {
    rep(k, 1, n + 1) {
        rep(i, 1, n + 1) { 
            rep(j, 1, n + 1) {
                if (d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main() {
    cin >> t;
    while (t--) {
        cin >> n;

        d.clear();
        sum = 0;
        d.assign(n + 1, vll(n + 1, INF));

        rep(i, 1, n + 1) {
            d[i][i] = 0;
        }

        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                cin >> d[i][j];
            }
        }

        floyd_warshall();

        cin >> m;
        rep(i, 0, m) {
            cin >> a >> b;
            sum += d[a][b]; 
        }

        cout << "Case #" << cnt++ << ": " << sum << '\n';

    }

    return 0;
}