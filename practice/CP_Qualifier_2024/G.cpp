#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, s;
double ans = 0.0;
int c;
multiset<int> g[100007];

int main () {
    // cin.tie(0)->sync_with_stdio(0);

    cin >> n;

    rep (i, 0, n) {
        cin >> s >> c;
        g[s].insert(c);
    }

    rep(i, 0, 100007) {
        if (!g[i].empty()) {
            auto b = g[i].begin();
            auto e = prev(g[i].end());
            while (distance(b, e) > 0) {
                int c_driving = *e;
                int c_driven = *b;
                ans += log(c_driving) - log(c_driven);
                ++b;
                if (b == e) break;
                --e;
            }
        }
    }
    cout << fixed << setprecision(16) << ans << "\n";
}