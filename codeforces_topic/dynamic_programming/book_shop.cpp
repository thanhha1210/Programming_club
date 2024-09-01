#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
const ll INF = 1e9;
const ll C1 = 1;
ll n, W;
vll p, v, F;

void knapsack() {
    rep(i, 0, n) {
        for (int j = W; j >= p[i]; j--) {
            F[j] = max(F[j], F[j - p[i]] + v[i]);
        }
    }
}

int main() {
    cin >> n >> W;
    p.resize(n);
    v.resize(n);
    F.assign(W + 1, 0);

    rep(i, 0, n) 
        cin >> p[i];
    rep(i, 0, n) 
        cin >> v[i];
    
    knapsack();
    cout << F[W];

}