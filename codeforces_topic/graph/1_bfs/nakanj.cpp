#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef pair<int, int> pii;
const vector<pii> moves = {{-2, -1}, {-1, -2}, {1, -2}, {2, -1}, {2, 1},  {1, 2},  {-1, 2}, {-2, 1}};

bool is_valid(int x, int y) {
    return (x >= 1 && x <= 8 && y >= 1 && y <= 8);
}

pii to_coordinates(string pos) {
    return {pos[0] - 'a' + 1, pos[1] - '0'};
}

int bfs(string start, string end) {
    pii src = to_coordinates(start);
    pii dest = to_coordinates(end);

    if (src == dest) 
        return 0;
    queue<pii> q;
    vector<vector<bool>> visited(9, vector<bool>(9, false));
    q.push(src);
    visited[src.first][src.second] = true;
    int moves_count = 0;

    while (!q.empty()) {
        int size = q.size();
        moves_count++;

        for (int i = 0; i < size; ++i) {
            pii curr = q.front();
            q.pop();

            for (auto move : moves) {
                int x = curr.first + move.first;
                int y = curr.second + move.second;

                if (x == dest.first && y == dest.second) return moves_count;

                if (is_valid(x, y) && !visited[x][y]) {
                    visited[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }
    return -1;

}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string start, end;
        cin >> start >> end;
        cout << bfs(start, end) << endl;
    }

    return 0;
}