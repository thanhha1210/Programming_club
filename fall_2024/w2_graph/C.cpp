#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;

const vpii adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const vc step = {'D', 'U', 'R', 'L'};

ll n, m, cnt = 0, xs, ys, xe, ye;
vvc grid, p;     
vvb visited;
vc res;


void bfs() {
    visited[xs][ys] = true;
    queue<pair<int, int>> q;
    q.push({xs, ys});
    while (!q.empty()) {
        pair<int , int> v = q.front();
        q.pop();
        rep(i, 0, adj.size()) {
            int x = v.first + adj[i].first;
            int y = v.second + adj[i].second;
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && (grid[x][y] == '.' || grid[x][y] == 'B' )) {
                q.push({x, y});
                p[x][y] = step[i];
                visited[x][y] = true;
                if (x == xe && y == ye) 
                    return;
            }
        }
    }
}
void backTrack() {
    int x = xe, y = ye;
    while(x != xs || y != ys) {
        res.push_back(p[x][y]);
        if (p[x][y] == 'U') x += 1;
        else if (p[x][y] == 'D') x -= 1;
        else if (p[x][y] == 'L') y += 1;
        else if (p[x][y] == 'R') y -= 1;
    }
        
    reverse(res.begin(), res.end());
    cout << "YES\n";
    cout << res.size() << '\n';

    for (auto c : res) {
        cout << c;
    }
    
}

int main() {
    cin >> n >> m;
    grid.assign(n, vc(m));
    visited.assign(n, vb(m, false));
    p.assign(n, vc(m, ' '));

    rep(i, 0, n) 
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                xs = i;
                ys = j;
            }
            else if (grid[i][j] == 'B') {
                xe = i;
                ye = j;
            }
        }
    bfs();
    if (!visited[xe][ye]) {
        cout << "NO\n";
    }
    else {
        backTrack();
    }
    return 0;
}