#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

const ll INF = 1e9 + 7;
ll t, maxN = 0;
vll k, n;
vvll C; 

void createC() {
    maxN += 10;
    C.assign(maxN, vll(maxN));

    rep(i, 1, maxN) {
        C[i][0] = 1;
        C[i][i] = 1;
        rep(j, 1, maxN) {
            C[i][j] = (C[i][j - 1] + C[i - 1][j - 1]) % INF;
        }
    }

    // rep(i, 0, maxN) {
    //     rep(j, 0, maxN) {
    //         cout << C[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}


int main() {
    cin >> t;
    k.resize(t);
    n.resize(t);
    rep(i, 0, t) {
        cin >> n[i];
        if (n[i] > maxN) 
            maxN = n[i];
    }
    rep(i, 0, t) {
        cin >> k[i];
    }

    createC();
    rep(i, 0, t) {
        cout << C[n[i]][k[i]] << "\n";
    }
}