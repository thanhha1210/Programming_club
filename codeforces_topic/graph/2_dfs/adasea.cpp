#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<bool>> vvb;
typedef vector<vector<char>> vvc;
typedef vector<pair<long long, long long>> vpll;

const vpll OP = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

long long t, n, m, d, sum;
vvc grid;
vvb visit;


bool isValid(long long a, long long b) {
    return (a >= 0 && a < n && b >= 0 && b < m);
}

void dfs(long long x, long long y) {
    visit[x][y] = true;
    d++;
    rep(i, 0, OP.size()) {
        long long x1 = x + OP[i].first, y1 = y + OP[i].second;
        if (isValid(x1, y1) && !visit[x1][y1] && grid[x1][y1] == '#') {
            dfs(x1, y1);
        }
    }
}


long long GCD(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}


void solve() {
    long long div = n * m;
    long long temp = GCD(sum, div);
    sum /= temp;
    div /= temp;

    if (div == 1) {
        cout << sum << '\n';
    }
    else {
        cout << sum << " / " << div << '\n';
    }
    
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        sum = 0;
        grid.clear();
        visit.clear();
        grid.resize(n, vector<char>(m));
        visit.assign(n, vector<bool>(m, false));
        rep(i, 0, n) {
            rep(j, 0, m) {
                cin >> grid[i][j];
            }
        }
        rep(i, 0, n) {
            rep(j, 0, m) {
                if (!visit[i][j] && grid[i][j]=='#') {
                    d = 0;
                    dfs(i, j);
                    sum += d * d;
                }
            }
        }
        solve();
    }
    return 0;

}