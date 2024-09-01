#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<bool> vb;typedef vector<vector<bool>> vvb;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;


typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;



int n, m, xs, ys, xe, ye;
int x, y;
vvpii p;
vvb check;

vvc grid;


void bfs() {
    queue<pii> q;
   
    q.push({xs, ys});
    check[x][y] = true;

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        
       
        if (x == xe && y == ye) {
            break;
        }

        if (x + 1 < n && !check[x + 1][y] && (grid[x + 1][y] == '.' || grid[x + 1][y] == 'B')) {
            p[x + 1][y].first = x;
            p[x + 1][y].second = y;
            check[x + 1][y] = true;
            q.push({x + 1, y});
        }

        if (x - 1 > 0 && !check[x - 1][y] && (grid[x - 1][y] == '.'|| grid[x - 1][y] == 'B')) {
            p[x - 1][y].first = x;
            p[x - 1][y].second = y;
            check[x - 1][y] = true;
            q.push({x - 1, y});
        }

        if (y + 1 < m && !check[x][y + 1] && (grid[x][y + 1] == '.'|| grid[x][y + 1] == 'B')) {
            p[x][y + 1].first = x;
            p[x][y + 1].second = y;
            check[x][y + 1] = true;
            q.push({x, y + 1});
        }

        if (y - 1 > 0 && !check[x][y - 1] && (grid[x][y - 1] == '.'|| grid[x][y - 1] == 'B')) {
            p[x][y - 1].first = x;
            p[x][y - 1].second = y;
            check[x][y - 1] = true;
            q.push({x, y - 1});
        }
    }

}

void backTrack() {
    
    int preX, preY;
    vc res;
    x = xe;
    y = ye;

    while (x != xs || y != ys) {
        preX = p[x][y].first;
        preY = p[x][y].second;

        if (x == preX - 1) {
            res.push_back('U');
        }
        else if (x == preX + 1) {
            res.push_back('D');
        }
        else if (y == preY - 1) {
            res.push_back('L');
        }
        else if (y == preY + 1) {
            res.push_back('R');
        }

        x = preX;
        y = preY;
    }

    cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i];
    }

}

void solve() {
    bfs();
    if (!check[xe][ye]) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        backTrack();
    }
    return;
}



int main() {
    cin >> n >> m;
    grid.assign(n , vc(m));

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                xs = i;
                ys = j;
            }
             if (grid[i][j] == 'B') {
                xe = i;
                ye = j;
            }
            
        }
    }  

    p.assign(n, vpii(m, {-1, -1}));
    check.assign(n, vb(m, false));

    solve();

}