#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

ll t, n, m;
vvc grid;
vll fr;
string s;

// Another way use bfs, if dist = 2 -> possible friend
int main() {
    cin >> t;
    while (t--) {
        cin >> s;
        m = s.length();
        grid.clear();
        fr.clear();
        grid.assign(m, vc(m));
        fr.assign(m, 0);

        rep(i, 0, m) {
            grid[0][i] = s[i];
        }
        rep(i, 1, m) {
            rep(j, 0, m) {
                cin >> grid[i][j];
            }
        }

        rep(i, 0, m) {
            rep(j, 0, m) {
                if (i != j && grid[i][j] == 'N') {
                    rep(k, 0, m) {
                        if (grid[i][k] == 'Y' && grid[k][j] == 'Y') {
                            fr[i]++;
                            break;
                        }
                    }
                }
            }
        }

        ll max_friends = -1, person_id = -1;

        rep(i, 0, m) {
            if (fr[i] > max_friends) {
                max_friends = fr[i];
                person_id = i;   
            }
        }  
        cout << person_id << " " << max_friends << '\n';
    }
    return 0;
}


