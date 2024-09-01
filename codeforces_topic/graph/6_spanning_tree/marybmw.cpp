#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

const long long INF = 1e18 + 7;

struct Edge {
    ll u, v, w;
    bool operator< (const Edge& o) const {
        return this->w < o.w;
    }
};

vll p, r;  // p holds the parent node, r holds the size of the tree
ll t, n, m, a, b, c, ans;
vector<Edge> edges;

void make_set() {
    p.resize(n + 1);
    r.assign(n + 1, 1);
    rep(i, 1, n + 1) {
        p[i] = i;
    }
}

ll find_set(ll v) {
    if (v == p[v]) {
        return v;
    } else {
        return p[v] = find_set(p[v]);  // Path compression
    }
}

void union_set(ll a, ll b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (r[a] < r[b]) {
            swap(a, b);
        }
        p[b] = a;
        r[a] += r[b];  // Union by rank
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> n >> m;
        ans = -1;
        edges.clear();
        make_set();

        rep(i, 0, m) {
            cin >> a >> b >> c;
            edges.push_back({a, b, c});
        }

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.w > b.w;  // Sort in descending order
        });

        for (Edge e : edges) {
            if (find_set(1) == find_set(n)) {
                break;
            }
            if (find_set(e.u) != find_set(e.v)) {
                union_set(e.u, e.v);
                if (find_set(1) == find_set(n)) {
                    ans = e.w;
                    break;
                }
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
