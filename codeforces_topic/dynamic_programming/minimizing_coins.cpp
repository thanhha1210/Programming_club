#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
const ll INF = 1e9;
const ll C1 = 1;
ll n, x;
vll c;
vll F;

void knapsack2() {
    rep(i, 0, n) {
        rep(j, c[i], x + 1) {
            if (F[j- c[i]] != INF) {
                F[j] = min(F[j], F[j - c[i]] + 1);
            }
        }
    }
}

int main() {
    cin >> n >> x;
    c.resize(n);
    F.assign(x + 1, INF);
    F[0] = 0;
    rep(i, 0, n) {
        cin >> c[i];
    }
    knapsack2();
    if (F[x] == INF) {
        cout << -1;  
    } else {
        cout << F[x];
    }

}