#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
int n;
const long long INF = 1e9 + 7;
vvll d;
vvc grid;

void dp() {
    rep(i, 0, n) {
        if (grid[i][0] == '.') 
            d[i][0] = 1;
        else 
            break;
    }
    rep(j, 0, n) {
        if (grid[0][j] == '.') 
            d[0][j] = 1;
        else 
            break;
    }

    rep(i, 1, n) {
        rep(j, 1, n) {
            if (grid[i][j] == '.') {
                d[i][j] = (d[i][j - 1] + d[i - 1][j]) % INF;
            }
        }
   }
   
}

int main() {
    cin >> n;
    d.assign(n, vll(n, 0));
    grid.assign(n, vc(n));
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> grid[i][j];
        }
    }
    dp();
    cout << d[n - 1][n - 1] << '\n';
    return 0;

}