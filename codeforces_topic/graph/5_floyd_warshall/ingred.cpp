#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


const long long INF = 1e12;
ll t, n, m, a, b, c, s, x1, x2;
vvll d;
vll store;

void floyd_warshall() {
    rep(k, 0, n) {
        rep(i, 0, n) { 
            rep(j, 0, n) {
                if (d[i][k] != INF && d[k][j] != INF)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}


int main() {
 
    cin >> n >> m;
    
    d.assign(n, vll(n, INF));
    rep(i, 0, n) {
        d[i][i] = 0;
    }

    rep(i, 0, m) {
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
    }

    floyd_warshall();

    cin >> s;
    store.resize(s);
    rep(i, 0, s) {
        cin >> store[i];
    }

    cin >> x1 >> x2;

    ll min_distance = INF;
    rep(i, 0, s) {
        ll total_distance = d[x1][store[i]] + d[x2][store[i]];
        min_distance = min(min_distance, total_distance);
    }

    cout << min_distance << '\n';
    

    return 0;
}