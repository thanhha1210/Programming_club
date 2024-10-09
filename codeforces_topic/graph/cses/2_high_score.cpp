#include <bits/stdc++.h>
using namespace std;

#define sz(a) (a).size()
#define rep(i, j, n) for (int i = 0; i < n; i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;
const ll INF = LLONG_MAX;

ll n, m, a, b, c;

struct Ed { 
    int a, b, w; 
    int s() { return a < b ? a : -a; }
};
struct Node { 
	ll dist = INF; 
	int prev = -1; 
};

void bellmanFord(vector<Node>& nodes, vector<Ed>& eds, int s) {
	nodes[s].dist = 0;
	sort(all(eds), [](Ed a, Ed b) { return a.s() < b.s(); });

	int lim = sz(nodes) / 2 + 2; // /3+100 with shuffled vertices
	rep(i, 0, lim) 
		for (Ed ed : eds) {
			Node cur = nodes[ed.a], &dest = nodes[ed.b];
			if (abs(cur.dist) == INF) continue;
			ll d = cur.dist + ed.w;
			if (d < dest.dist) {
				dest.prev = ed.a;
				dest.dist = (i < lim-1 ? d : -INF);
			}
		}
	rep(i,0,lim) for (Ed e : eds) {
		if (nodes[e.a].dist == -INF)
			nodes[e.b].dist = -INF;
	}
}

int main() {
	cin >> n >> m;
	vector<Node> nodes(n + 1);
	vector<Ed> eds();

	rep(i, 0, m) {
		cin >> a >> b >> c;
		eds.push_back({a, b, c});
	}

	bellmanFord(nodes, eds, 1);

	if (nodes[n].dist == -INF) {
		cout << "contain neg cycle";
	} else if (nodes[n].dist == INF) {
		cout << "No path to node " << n;
	} else {
		cout << "Shortest path to node " << n << " is " << nodes[n].dist;
	}
}