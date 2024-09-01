#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
const ll INF = 1e9 + 7;
ll n, x;
vll c, F;
void knapsack() {
    F[0] = 1;
    rep(i, 0, n) 
        rep(j, c[i], x + 1) 
            F[j] = (F[j - c[i]] + F[j]) % INF; 
}



int main() {
    cin >> n >> x;
    c.resize(n);
    F.assign(x + 1, INF);
   
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