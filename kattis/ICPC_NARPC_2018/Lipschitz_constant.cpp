#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
const double INF = 1e13;
ll n;
double a, b, x = -INF, y = -INF;
double maxn = 0.0;

struct Point {
    int x;
    double fx;
};

int main() {
    cin >> n;
    vector<Point> points(n);
    rep(i, 0, n) {
        cin >> points[i].x >> points[i].fx;
    }
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) {
        return a.x < b.x;
    });

    for (int i = 1; i < n; ++i) {
        double ratio = abs(points[i].fx - points[i - 1].fx) / abs(points[i].x - points[i - 1].x);
        maxn = max(maxn, ratio);
    }
    cout << fixed << setprecision(6) << maxn << endl;
    return 0;
}
