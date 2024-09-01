#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


struct Edge {
    ll u, v, w;
    bool operator< (const Edge& o) const {
        return this->w < o.w;
    }
};

const long long INF = 1e9;
ll t, n, m, a, b, c, ans;
vector<Edge> edges;
vll p, r;
string s;

void make_set() {
    p.assign(n + 1, -1);
    r.assign(n + 1, 1);
    rep(i, 1, n + 1) {
        p[i] = i;
    }
}

ll find_set(ll v) {
    if (v == p[v]) {
        return v;
    }
    else {
        return p[v] = find_set(p[v]);
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
        r[a] += r[b];
    }
}



int main() {
    cin >> t;
    while (t--) {
        edges.clear();
        ans = 0;
        cin >> n;
        make_set();
        rep(i, 1, n + 1) {
            cin >> s;
            cin >> m;
            rep(j, 0, m) {
                cin >> b >> c;
                edges.push_back({i, b, c});
            }   
        }

        sort(edges.begin(), edges.end());

        for (Edge e : edges) {
            ll u = e.u, v = e.v, w = e.w;
            if (find_set(u) != find_set(v)) {
                ans += w;
                union_set(u, v); 
            }
        }

        cout << ans << '\n';

    }
}
