#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
int n, m, cnt = 0;
vvc grid, res;

int main() {
    cin >> n >> m;
    grid.assign(n, vc(m));
    res.assign(n, vc(m, '.'));
    rep(i, 0, n) 
        rep(j, 0, m)
            cin >> grid[i][j];
    

    rep(j, 0, m) {
        int index = n - 1, i = n - 1;
        while (i >= 0) {
            if (grid[i][j] == '#') {
                res[i][j] = '#';
                index = i - 1;
            }
            else if (grid[i][j] == 'o') {
                res[index][j] = 'o';
                while ((index >= 0) && res[index][j] != '.') {
                    index--;
                }
            }
            i--;
        }
    }

    rep(i, 0, n) {
        rep(j, 0, m)
            cout << res[i][j];
        cout << '\n';
    }
        
}