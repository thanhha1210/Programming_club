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
typedef vector<vector<int>> vvi;

const int INF = 1e9;
const vpii adj = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};    // Directions for BFS
const vc step = {'D', 'U', 'R', 'L'};                  // Corresponding movement

ll n, m, xs, ys;
vvc grid, p;
vvi us, mon; 
vpii monsters;     
vvb visited;
vc res;

void bfs_monster() {
    visited.clear();
    visited.assign(n, vb(m, false));
    queue<pair<int, int>> q;
    for (auto monster : monsters) {
        q.push(monster);
        mon[monster.first][monster.second] = 0;
    }

    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        rep(i, 0, adj.size()) {
            int x = v.first + adj[i].first;
            int y = v.second + adj[i].second;
            if (x >= 0 && x < n && y >= 0 && y < m && mon[x][y] == INF && (grid[x][y] == '.' || grid[x][y] == 'A')) {
                mon[x][y] = mon[v.first][v.second] + 1;
                q.push({x, y});
            }
        }
    }
}

void bfs_us() {
    visited[xs][ys] = true;
    us[xs][ys] = 0;
    queue<pair<int, int>> q;
    q.push({xs, ys});
    while (!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        rep(i, 0, adj.size()) {
            int x = v.first + adj[i].first;
            int y = v.second + adj[i].second;
            if (x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && us[v.first][v.second] + 1 < mon[x][y] && grid[x][y] == '.') {
                q.push({x, y});
                us[x][y] = us[v.first][v.second] + 1;
                p[x][y] = step[i];
                visited[x][y] = true;
            }
        }
    }
}

void backTrack(int xe, int ye) {
    int x = xe, y = ye;
    while (x != xs || y != ys) {
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
    cout << '\n';
}

int main() {
    cin >> n >> m;
    grid.assign(n, vc(m));
    visited.assign(n, vb(m, false));
    p.assign(n, vc(m, ' '));
    us.assign(n, vi(m, INF));
    mon.assign(n, vi(m, INF));

    rep(i, 0, n) {
        rep(j, 0, m) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                xs = i;
                ys = j;
            } 
            else if (grid[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }

    bfs_monster();
    bfs_us();

    bool check = false;
    rep(i, 0, n) {
        if (us[i][0] != INF) {
            backTrack(i, 0);
            check = true;
            break;
        }
        if (us[i][m-1] != INF) {
            backTrack(i, m-1);
            check = true;
            break;
        }
    }
    if (!check) {
        rep(i, 0, m) {
            if (us[0][i] != INF) {
                backTrack(0, i);
                check = true;
                break;
            }
            if (us[n-1][i] != INF) {
                backTrack(n-1, i);
                check = true;
                break;
            }     
        }
    }
    if (!check) {
        cout << "NO\n";
    }

    return 0;
}
