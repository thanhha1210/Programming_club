#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
const ll INF = 1e9 + 7;
ll n, x;
vll c, F;
void knapsack2() {
    rep(i, 0, x + 1) {
        rep(j, 0, n) {
            if (i >= c[j]) {
                F[i] += F[i - c[j]];
                F[i] = F[i] % INF;
            }
        }
    }
}



int main() {
    cin >> n >> x;
    c.resize(n);
    F.assign(x + 1, INF);
    F[0] = 1;
    rep(i, 0, n) {
        cin >> c[i];
    }
    knapsack();
    if (F[x] == INF) {
        cout << 0;  
    } else {
        cout << F[x];
    }
    return 0;

}