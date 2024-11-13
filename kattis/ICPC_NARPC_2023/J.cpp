#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;

ll n, k, sum = 0, e, maxn = 0, need, tar;

int main() {
    cin >> n >> k;
    rep(i, 0, n) {
        cin >> e;
        sum += e;
        maxn = max(maxn, e);
    }
    need = (sum - 1) / k + 1; // round up (round down if less), then + 1 => round up 
    tar = max(need, maxn) * k;  
    cout << tar - sum;
}