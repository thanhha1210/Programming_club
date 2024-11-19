#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<double> vd;
typedef vector<vd> vvd;

struct Point {
    double x, y;
    double dis(const Point& o) {
        return sqrt((x - o.x) * (x - o.x) + (y - o.y) * (y - o.y));
    }
};

struct Edge {
    ll u, v;      // index of points (tree houses)
    double w;     // length between the two points
    bool operator<(const Edge& e) const {
        return w < e.w;
    }
};

typedef vector<Edge> ve;
typedef vector<Point> vp;
vp pts;
ve edges;
vector<ll> p, r;

ll find_set(ll v) {
    if (v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

void union_set(ll a, ll b) {
    a = find_set(a); b = find_set(b);
    if (a != b) {
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        r[a] += r[b];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // n = number of tree houses, e = number of existing cables
    // b = number of tree houses near open land
    int n, e, b; 
    cin >> n >> e >> b;

    pts.assign(n + 1, Point()); 
    p.assign(n + 1, 0);
    r.assign(n + 1, 1);

    rep(i, 1, n + 1) {
        cin >> pts[i].x >> pts[i].y; 
    }

    // Initialize union-find
    rep(i, 1, n + 1) p[i] = i;
    rep(i, 2, e + 1) {
        union_set(1, i);
    }
    // Read the existing cables and union the connected nodes
    rep(i, 0, b) {
        ll u, v;
        cin >> u >> v;
        union_set(u, v);
    }

    // Now, add all possible edges between treehouses
    rep(i, 1, n + 1) {
        rep(j, i + 1, n + 1) {
            double dist = pts[
                i].dis(pts[j]);
            edges.push_back(Edge{i, j, dist});
        }
    }

    // Sort edges by weight (distance)
    sort(edges.begin(), edges.end());

    // Kruskal's Algorithm to find the MST (Minimum Spanning Tree)
    double total_length = 0;
    int added_edges = 0;
    for (const auto& edge : edges) {
        if (find_set(edge.u) != find_set(edge.v)) {
            union_set(edge.u, edge.v);
            total_length += edge.w;
            added_edges++;
            if (added_edges == n - 1) break;  // We have connected all the tree houses
        }
    }

    // Output the total length of cable added
    cout << fixed << setprecision(6) << total_length << endl;
    return 0;
}
